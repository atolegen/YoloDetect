using System;
using System.Collections;
using System.Collections.Generic;
using System.Threading.Tasks;

#if ENABLE_WINMD_SUPPORT
using Windows.UI.Xaml;
using HoloLensForCV;
using YoloRuntime;
#endif

using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.WSA.Input;

using DrawingUtils;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using System.Text;

#if !UNITY_EDITOR
    using Windows.Networking;
    using Windows.Networking.Sockets;
    using Windows.Storage.Streams;
#endif
// https://devblogs.microsoft.com/dotnet/ml-net-and-model-builder-at-net-conf-2019-machine-learning-for-net/?utm_source=vs_developer_news&utm_medium=referral
namespace YoloDetectionHoloLens
{
    // Using the hololens for cv .winmd file for runtime support
    // https://docs.unity3d.com/2018.4/Documentation/Manual/IL2CPP-WindowsRuntimeSupport.html
    public class YoloDetection : MonoBehaviour
    {
        #region UnityVariables
        // Gesture recognizer
        private GestureRecognizer _gestureRecognizer;

        // Texture handler for bounding boxes
        public DrawBoundingBoxes drawBoundingBoxes;

        // Parameters for host connect
        // https://stackoverflow.com/questions/32876966/how-to-get-local-host-name-in-c-sharp-on-a-windows-10-universal-app
        // Connecting to desktop host IP, not the hololens... Get the IP of PC and retry with specified port 
        public string ipAddressForConnect = "000.00.00.0";
        public string hostId = "12345";

        public Text myText;
        int _tapCount;
        string _input;
        int bbid;
        float x, y, w, h;
        string[] sArray;
        

        // From Tiny YOLO string labels.
        private string[] _labels = {            
            "person","bicycle","car","motorbike","aeroplane","bus","train","truck","boat","traffic light","fire hydrant","stop sign","parking meter",
             "bench","bird","cat","dog","horse","sheep","cow","elephant","bear","zebra","giraffe","backpack","umbrella","handbag","tie","suitcase",
             "frisbee","skis","snowboard","sports ball","kite","baseball bat","baseball glove","skateboard","surfboard","tennis racket","bottle",
             "wine glass","cup","fork","knife","spoon","bowl","banana","apple","sandwich","orange","broccoli","carrot","hot dog","pizza","donut",
             "cake","chair","sofa","pottedplant","bed","diningtable","toilet","tvmonitor","laptop","mouse","remote","keyboard","cell phone","microwave",
             "oven","toaster","sink","refrigerator","book","clock","vase","scissors","teddy bear","hair drier","toothbrush"
        };

        private bool _holoLensMediaFrameSourceGroupStarted;
        //ds
        Thread mThread;
        public string connectionIP = "192.168.43.27";
        public int connectionPort = 12345;
        IPAddress localAdd;
        TcpListener listener;
        TcpClient client;
        Vector3 pos = Vector3.zero;



        bool running;

#if !UNITY_EDITOR
        StreamSocket socket1;
        StreamSocketListener listener1;
        String port1;
        String message1;
#endif

        public enum SensorTypeUnity
        {
            Undefined = -1,
            PhotoVideo = 0,
            ShortThrowToFDepth = 1,
            ShortThrowToFReflectivity = 2,
            LongThrowToFDepth = 3,
            LongThrowToFReflectivity = 4,
            VisibleLightLeftLeft = 5,
            VisibleLightLeftFront = 6,
            VisibleLightRightFront = 7,
            VisibleLightRightRight = 8,
            NumberOfSensorTypes = 9
        }
        public SensorTypeUnity sensorTypePv;
        #endregion

#if ENABLE_WINMD_SUPPORT
        // Required for media frame source initialization
        private MediaFrameSourceGroupType _selectedMediaFrameSourceGroupType = MediaFrameSourceGroupType.PhotoVideoCamera;
        private SensorFrameStreamer _sensorFrameStreamer;
        private SpatialPerception _spatialPerception;
        private MediaFrameSourceGroup _holoLensMediaFrameSourceGroup;
        private SensorType _sensorType;
#endif

        #region UnityMethods
        // Use this for initialization
        async void Start()
        {
            // Create the gesture handler
            InitializeHandler();

            // Initialize the bounding box canvas
            drawBoundingBoxes.InitDrawBoundingBoxes();

            // Wait for media frame source groups to be initialized
            await StartHoloLensMediaFrameSourceGroup();
        }

        async void OnApplicationQuit()
        {
            await StopHoloLensMediaFrameSourceGroup();
        }

        #endregion

        /// <summary>
        /// Initialize and start the hololens media frame source groups
        /// </summary>
        /// <returns>Task result</returns>

        void Update()
        {
            myText.text = _input;
        }
        async Task StartHoloLensMediaFrameSourceGroup()
        {
#if ENABLE_WINMD_SUPPORT
            // Plugin doesn't work in the Unity editor
 
            _input= "Initalizing MediaFrameSourceGroup.";

            Debug.Log("YoloDetection.Detection.StartHoloLensMediaFrameSourceGroup: Setting up sensor frame streamer");
            _sensorType = (SensorType)sensorTypePv;
            _sensorFrameStreamer = new SensorFrameStreamer();
            _sensorFrameStreamer.Enable(_sensorType);

            Debug.Log("YoloDetection.Detection.StartHoloLensMediaFrameSourceGroup: Setting up spatial perception");
            _spatialPerception = new SpatialPerception();

            Debug.Log("YoloDetection.Detection.StartHoloLensMediaFrameSourceGroup: Setting up the media frame source group");
            _holoLensMediaFrameSourceGroup = new MediaFrameSourceGroup(
                _selectedMediaFrameSourceGroupType,
                _spatialPerception,
                _sensorFrameStreamer);
            _holoLensMediaFrameSourceGroup.Enable(_sensorType);

            Debug.Log("YoloDetection.Detection.StartHoloLensMediaFrameSourceGroup: Starting the media frame source group");
            await _holoLensMediaFrameSourceGroup.StartAsync();
            _holoLensMediaFrameSourceGroupStarted = true;

            //myText.text 
            _input = "MediaFrameSourceGroup started. Once desktop client is connected, double tap to connect to host socket.";

#endif
        }

        async Task StopHoloLensMediaFrameSourceGroup()
        {
#if ENABLE_WINMD_SUPPORT
            if (_holoLensMediaFrameSourceGroup == null || 
                !_holoLensMediaFrameSourceGroupStarted)
            {
                return;
            }

            await _holoLensMediaFrameSourceGroup.StopAsync();
            _holoLensMediaFrameSourceGroup = null;
            _sensorFrameStreamer = null;
            _holoLensMediaFrameSourceGroupStarted = false;
#endif
        }

        /// <summary>
        /// Connect to the desktop client and begin receiving 
        /// bounding box information.
        /// </summary>
        /// <returns></returns>
        private IEnumerator ConnectSocket()
        {
#if ENABLE_WINMD_SUPPORT

            _input = "Connecting to host socket.";

            listener = new TcpListener(IPAddress.Any, 9090);
            listener.Start();
            if (!listener.Pending())
             {
                _input="Connecting to host socket.1111";
             }

            client = listener.AcceptTcpClient();
            
            // Loop indefinitely
            while (true)
            {
                // Get new updated bounding box results

                NetworkStream nwStream = client.GetStream();
                byte[] buffer = new byte[client.ReceiveBufferSize];

            
                int bytesRead = nwStream.Read(buffer, 0, client.ReceiveBufferSize);
                string dataReceived = Encoding.UTF8.GetString(buffer, 0, bytesRead);
            
                if (dataReceived != null)
                {                
                   _input = "Received"+dataReceived;
                }
            
                var dataBuffer1 = dataReceived.Split(':');

                List<BoundingBox> boundingBoxes = new List<BoundingBox>();

                // Iterate across data buffer, which is the total number of 
                // elements in the buffer
                const int boxSize = 6;
                
                if (dataBuffer1[0] != "00")
                {
                    var numBoxes = (int)(dataBuffer1.Length / (float)boxSize);

                    for (var boxCount = 0; boxCount < numBoxes; boxCount++)
                    {
                        BoundingBox box = new BoundingBox
                        {
                            TopLabel = int.Parse( dataBuffer1[(boxCount * boxSize) + 0]), // TopLabel is int
                            X = float.Parse(dataBuffer1[(boxCount * boxSize) + 1]),
                            Y = float.Parse(dataBuffer1[(boxCount * boxSize) + 2]),

                            Height = float.Parse(dataBuffer1[(boxCount * boxSize) + 3]),
                            Width = float.Parse(dataBuffer1[(boxCount * boxSize) + 4]),

                            Confidence = float.Parse(dataBuffer1[(boxCount * boxSize) + 5])
                            
                        };
                        _input=boxCount.ToString();
                        // Set top label from the label string by index.
                        box.Label = _labels[box.TopLabel];

                        // Add the filled box to list
                        boundingBoxes.Add(box);
                    }

                    // Draw the list of boxes
                    drawBoundingBoxes.DrawBoxes(boundingBoxes);

                    // Debug the text string outside of loop
                    yield return new WaitForSeconds(0.05f);
                    //_input = dataBuffer.Length.ToString();
                    //_input =$"Received {boundingBoxes.Count} bounding boxes.";
                    //Debug.Log(textString);
                }
                else
                {
                    // Draw the list of empty boxes to clear
                    // prior elements
                    boundingBoxes.Add(new BoundingBox()
                    {
                        Confidence = 0,
                        Label = "",
                        Height = 0,
                        Width = 0,
                        X = 0,
                        Y = 0});
                    drawBoundingBoxes.DrawBoxes(boundingBoxes);

                    _input = "No bounding boxes received.";
                    yield return new WaitForSeconds(0.05f);
                }
            }
#endif
            yield return new WaitForSeconds(3f);
        }

        #region TapGestureHandler
        private void InitializeHandler()
        {
            // New recognizer class
            _gestureRecognizer = new GestureRecognizer();

            // Set tap as a recognizable gesture
            _gestureRecognizer.SetRecognizableGestures(GestureSettings.DoubleTap);

            // Begin listening for gestures
            _gestureRecognizer.StartCapturingGestures();

            // Capture on gesture events with delegate handler
            _gestureRecognizer.Tapped += GestureRecognizer_Tapped;

            Debug.Log("Gesture recognizer initialized.");
        }

        public void GestureRecognizer_Tapped(TappedEventArgs obj)
        {
            // Connect to socket on tapped event
            _tapCount += obj.tapCount;
            //myText.text = "Ladno";
            Debug.LogFormat("OnTappedEvent: tapCount = {0}", _tapCount);
            StartCoroutine(ConnectSocket());
            /*myText.text = "Birjan sal Kojagululy";
            StartCoroutine(testconn());
            myText.text = "Akan seri";*/
            //Startt();
            //GetInfo();
        }

        void CloseHandler()
        {
            _gestureRecognizer.StopCapturingGestures();
            _gestureRecognizer.Dispose();
        }
        #endregion



        #region New receive
        void Connection()
        {
            
            NetworkStream nwStream = client.GetStream();
            byte[] buffer = new byte[client.ReceiveBufferSize];

            
            int bytesRead = nwStream.Read(buffer, 0, client.ReceiveBufferSize);
            string dataReceived = Encoding.UTF8.GetString(buffer, 0, bytesRead);
            
            if (dataReceived != null)
            {
                
                if (dataReceived == "stop")
                {
                    running = false;
                }
                else
                {
                    //pos = 10f * StringToVector3(dataReceived);

                    //print("moved");
                   _input = "Received"+dataReceived;
                    //nwStream.Write(buffer, 0, bytesRead);
                }
            }
        }
        public static Vector3 StringToVector3(string sVector)
        {
            // Remove the parentheses
            if (sVector.StartsWith("(") && sVector.EndsWith(")"))
            {
                sVector = sVector.Substring(1, sVector.Length - 2);
            }

            // split the items
            string[] sArray = sVector.Split(',');

            // store as a Vector3
            Vector3 result = new Vector3(float.Parse(sArray[0]), float.Parse(sArray[1]), float.Parse(sArray[2]));

            return result;
        }
        private IEnumerator testconn()
        {
            myText.text = "Why it is working?";
            localAdd = IPAddress.Parse(connectionIP);
            listener = new TcpListener(IPAddress.Any, connectionPort);
            listener.Start();

            client = listener.AcceptTcpClient();


            running = true;
            while (running)
            {
                Connection();
            }
            yield return new WaitForSeconds(0.05f);
        }

        private void Startt()
        {
            //ThreadStart ts = new ThreadStart(GetInfo);
            //mThread = new Thread(ts);
            //mThread.Start();
        }

        void GetInfo()
        {
#if !UNITY_EDITOR
        listener1 = new StreamSocketListener();
        port1 = "9090";
        //rrrrrrrrrrrrrr
        listener = new TcpListener(IPAddress.Any, 9090);
            listener.Start();
            if (!listener.Pending())
             {
                _input="Connecting to host socket.1111";
             }

            client = listener.AcceptTcpClient();
            _input="Okokokok";
            Connection();
        //eeeeeeeeeeeeeeeeeeeeeeeeeeeeee


        /*listener1.ConnectionReceived += Listener_ConnectionReceived;
        
        listener1.Control.KeepAlive = false;
        Listener_Start();
        */
#endif
        }
#if !UNITY_EDITOR
        private async void Listener_Start() {
        //myText.text = "halau lilauchik25";
        Debug.Log("Listener started");
        try
            {
                await listener1.BindServiceNameAsync(port1);
            }
        catch (Exception e)
            {
                Debug.Log("Error: " + e.Message);
            }
            Debug.Log("Listening");
            //myText.text += "halau lilauchik";


    }
    private async void Listener_ConnectionReceived(StreamSocketListener sender, StreamSocketListenerConnectionReceivedEventArgs args)
        {
            Debug.Log("Connection received");
            string ab="";
            
            try
            {
                while (true)
                {
                    using (var dr = new DataReader(args.Socket.InputStream))
                    {
                        dr.InputStreamOptions = InputStreamOptions.Partial;
                        await dr.LoadAsync(24);
                        var input= dr.ReadString(24);
                        ab=input;
                    }
                    

                    using (var dw = new DataWriter(args.Socket.OutputStream))
                    {
                        
                        dw.WriteString(ab);
                        await dw.StoreAsync();
                        dw.DetachStream();
                    }
                    string[] input2= ab.Split(':');
                    Databuffer1(input2);
                    
                }
            }
            catch (Exception e)
            {
                Debug.Log("disconnected!!!!!!!! " + e);
                myText.text="tuka";
            }
            sender.Dispose();
            }
#endif
        public IEnumerator Databuffer1(string[] input2)//int l,float x,float y,float w, float h,float c)
         {
#if ENABLE_WINMD_SUPPORT
                   int l=int.Parse(input2[0]);
                   float x=float.Parse(input2[1]);
                   float y=float.Parse(input2[2]);
                   float w=float.Parse(input2[3]);
                   float h=float.Parse(input2[4]);
                   float c=float.Parse(input2[5]);
                 //_input=l.ToString()+x.ToString()+y.ToString()+w.ToString()+h.ToString()+c.ToString();
                 List<BoundingBox> boundingBoxes = new List<BoundingBox>();

                 BoundingBox box = new BoundingBox
                         {
                             TopLabel = l,
                             X = x,
                             Y = y,

                             Height =h, 
                             Width = w,

                             Confidence =c};
                             
                 box.Label = _labels[box.TopLabel];

                 boundingBoxes.Add(box);
                 //_input=box.TopLabel.ToString()+box.X.ToString()+box.Y.ToString()+box.Height.ToString()+box.Width.ToString()+box.Confidence.ToString();
                 drawBoundingBoxes.DrawBoxes(boundingBoxes);
                 
                 _input = "Received bounding boxes.";
                 yield return new WaitForSeconds(0.05f);
#endif
            yield return new WaitForSeconds(0.05f);
        }
    }

    #endregion
}




