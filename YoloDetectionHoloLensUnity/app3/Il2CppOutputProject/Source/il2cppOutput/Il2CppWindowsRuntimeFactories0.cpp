#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <stdint.h>

#include "il2cpp-class-internals.h"
#include "codegen/il2cpp-codegen.h"
#include "vm/ActivationFactoryBase.h"
#include "il2cpp-object-internals.h"

template <typename R>
struct VirtFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};

// System.String
struct String_t;
// YoloRuntime.BoundingBox
struct BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E;
// YoloRuntime.WinMlParser
struct WinMlParser_tF43E30ACEBEBD40276CE104A6667BB01D57B1955;
// YoloRuntime.WinMlParserInterop
struct WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954;

extern RuntimeClass* BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E_il2cpp_TypeInfo_var;
extern RuntimeClass* String_t_il2cpp_TypeInfo_var;
extern RuntimeClass* WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954_il2cpp_TypeInfo_var;
extern const uint32_t BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E_Factory_ActivateInstance_MetadataUsageId;
extern const uint32_t WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954_Factory_ActivateInstance_MetadataUsageId;
struct IBoundingBoxClass_tD87A26227778A4583BFB754E6169E9E119275506;
struct IWinMlParserInteropClass_tF7BA16AD16B5303B4DDD9C671FD729A1586CEDC2;



#ifndef RUNTIMEOBJECT_H
#define RUNTIMEOBJECT_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Object

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // RUNTIMEOBJECT_H
#ifndef STRING_T_H
#define STRING_T_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.String
struct  String_t  : public RuntimeObject
{
public:
	// System.Int32 System.String::m_stringLength
	int32_t ___m_stringLength_0;
	// System.Char System.String::m_firstChar
	Il2CppChar ___m_firstChar_1;

public:
	inline static int32_t get_offset_of_m_stringLength_0() { return static_cast<int32_t>(offsetof(String_t, ___m_stringLength_0)); }
	inline int32_t get_m_stringLength_0() const { return ___m_stringLength_0; }
	inline int32_t* get_address_of_m_stringLength_0() { return &___m_stringLength_0; }
	inline void set_m_stringLength_0(int32_t value)
	{
		___m_stringLength_0 = value;
	}

	inline static int32_t get_offset_of_m_firstChar_1() { return static_cast<int32_t>(offsetof(String_t, ___m_firstChar_1)); }
	inline Il2CppChar get_m_firstChar_1() const { return ___m_firstChar_1; }
	inline Il2CppChar* get_address_of_m_firstChar_1() { return &___m_firstChar_1; }
	inline void set_m_firstChar_1(Il2CppChar value)
	{
		___m_firstChar_1 = value;
	}
};

struct String_t_StaticFields
{
public:
	// System.String System.String::Empty
	String_t* ___Empty_5;

public:
	inline static int32_t get_offset_of_Empty_5() { return static_cast<int32_t>(offsetof(String_t_StaticFields, ___Empty_5)); }
	inline String_t* get_Empty_5() const { return ___Empty_5; }
	inline String_t** get_address_of_Empty_5() { return &___Empty_5; }
	inline void set_Empty_5(String_t* value)
	{
		___Empty_5 = value;
		Il2CppCodeGenWriteBarrier((&___Empty_5), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // STRING_T_H
#ifndef BOUNDINGBOX_T2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E_H
#define BOUNDINGBOX_T2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// YoloRuntime.BoundingBox
struct  BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E  : public RuntimeObject
{
public:
	// System.String YoloRuntime.BoundingBox::<Label>k__BackingField
	String_t* ___U3CLabelU3Ek__BackingField_0;
	// System.Int32 YoloRuntime.BoundingBox::<TopLabel>k__BackingField
	int32_t ___U3CTopLabelU3Ek__BackingField_1;
	// System.Single YoloRuntime.BoundingBox::<X>k__BackingField
	float ___U3CXU3Ek__BackingField_2;
	// System.Single YoloRuntime.BoundingBox::<Y>k__BackingField
	float ___U3CYU3Ek__BackingField_3;
	// System.Single YoloRuntime.BoundingBox::<Height>k__BackingField
	float ___U3CHeightU3Ek__BackingField_4;
	// System.Single YoloRuntime.BoundingBox::<Width>k__BackingField
	float ___U3CWidthU3Ek__BackingField_5;
	// System.Single YoloRuntime.BoundingBox::<Confidence>k__BackingField
	float ___U3CConfidenceU3Ek__BackingField_6;

public:
	inline static int32_t get_offset_of_U3CLabelU3Ek__BackingField_0() { return static_cast<int32_t>(offsetof(BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E, ___U3CLabelU3Ek__BackingField_0)); }
	inline String_t* get_U3CLabelU3Ek__BackingField_0() const { return ___U3CLabelU3Ek__BackingField_0; }
	inline String_t** get_address_of_U3CLabelU3Ek__BackingField_0() { return &___U3CLabelU3Ek__BackingField_0; }
	inline void set_U3CLabelU3Ek__BackingField_0(String_t* value)
	{
		___U3CLabelU3Ek__BackingField_0 = value;
		Il2CppCodeGenWriteBarrier((&___U3CLabelU3Ek__BackingField_0), value);
	}

	inline static int32_t get_offset_of_U3CTopLabelU3Ek__BackingField_1() { return static_cast<int32_t>(offsetof(BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E, ___U3CTopLabelU3Ek__BackingField_1)); }
	inline int32_t get_U3CTopLabelU3Ek__BackingField_1() const { return ___U3CTopLabelU3Ek__BackingField_1; }
	inline int32_t* get_address_of_U3CTopLabelU3Ek__BackingField_1() { return &___U3CTopLabelU3Ek__BackingField_1; }
	inline void set_U3CTopLabelU3Ek__BackingField_1(int32_t value)
	{
		___U3CTopLabelU3Ek__BackingField_1 = value;
	}

	inline static int32_t get_offset_of_U3CXU3Ek__BackingField_2() { return static_cast<int32_t>(offsetof(BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E, ___U3CXU3Ek__BackingField_2)); }
	inline float get_U3CXU3Ek__BackingField_2() const { return ___U3CXU3Ek__BackingField_2; }
	inline float* get_address_of_U3CXU3Ek__BackingField_2() { return &___U3CXU3Ek__BackingField_2; }
	inline void set_U3CXU3Ek__BackingField_2(float value)
	{
		___U3CXU3Ek__BackingField_2 = value;
	}

	inline static int32_t get_offset_of_U3CYU3Ek__BackingField_3() { return static_cast<int32_t>(offsetof(BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E, ___U3CYU3Ek__BackingField_3)); }
	inline float get_U3CYU3Ek__BackingField_3() const { return ___U3CYU3Ek__BackingField_3; }
	inline float* get_address_of_U3CYU3Ek__BackingField_3() { return &___U3CYU3Ek__BackingField_3; }
	inline void set_U3CYU3Ek__BackingField_3(float value)
	{
		___U3CYU3Ek__BackingField_3 = value;
	}

	inline static int32_t get_offset_of_U3CHeightU3Ek__BackingField_4() { return static_cast<int32_t>(offsetof(BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E, ___U3CHeightU3Ek__BackingField_4)); }
	inline float get_U3CHeightU3Ek__BackingField_4() const { return ___U3CHeightU3Ek__BackingField_4; }
	inline float* get_address_of_U3CHeightU3Ek__BackingField_4() { return &___U3CHeightU3Ek__BackingField_4; }
	inline void set_U3CHeightU3Ek__BackingField_4(float value)
	{
		___U3CHeightU3Ek__BackingField_4 = value;
	}

	inline static int32_t get_offset_of_U3CWidthU3Ek__BackingField_5() { return static_cast<int32_t>(offsetof(BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E, ___U3CWidthU3Ek__BackingField_5)); }
	inline float get_U3CWidthU3Ek__BackingField_5() const { return ___U3CWidthU3Ek__BackingField_5; }
	inline float* get_address_of_U3CWidthU3Ek__BackingField_5() { return &___U3CWidthU3Ek__BackingField_5; }
	inline void set_U3CWidthU3Ek__BackingField_5(float value)
	{
		___U3CWidthU3Ek__BackingField_5 = value;
	}

	inline static int32_t get_offset_of_U3CConfidenceU3Ek__BackingField_6() { return static_cast<int32_t>(offsetof(BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E, ___U3CConfidenceU3Ek__BackingField_6)); }
	inline float get_U3CConfidenceU3Ek__BackingField_6() const { return ___U3CConfidenceU3Ek__BackingField_6; }
	inline float* get_address_of_U3CConfidenceU3Ek__BackingField_6() { return &___U3CConfidenceU3Ek__BackingField_6; }
	inline void set_U3CConfidenceU3Ek__BackingField_6(float value)
	{
		___U3CConfidenceU3Ek__BackingField_6 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // BOUNDINGBOX_T2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E_H
#ifndef WINMLPARSERINTEROP_TA4651E220A7C199CFEB91E9B6FD3CB183C6C0954_H
#define WINMLPARSERINTEROP_TA4651E220A7C199CFEB91E9B6FD3CB183C6C0954_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// YoloRuntime.WinMlParserInterop
struct  WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954  : public RuntimeObject
{
public:
	// YoloRuntime.WinMlParser YoloRuntime.WinMlParserInterop::winMlParser
	WinMlParser_tF43E30ACEBEBD40276CE104A6667BB01D57B1955 * ___winMlParser_0;

public:
	inline static int32_t get_offset_of_winMlParser_0() { return static_cast<int32_t>(offsetof(WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954, ___winMlParser_0)); }
	inline WinMlParser_tF43E30ACEBEBD40276CE104A6667BB01D57B1955 * get_winMlParser_0() const { return ___winMlParser_0; }
	inline WinMlParser_tF43E30ACEBEBD40276CE104A6667BB01D57B1955 ** get_address_of_winMlParser_0() { return &___winMlParser_0; }
	inline void set_winMlParser_0(WinMlParser_tF43E30ACEBEBD40276CE104A6667BB01D57B1955 * value)
	{
		___winMlParser_0 = value;
		Il2CppCodeGenWriteBarrier((&___winMlParser_0), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // WINMLPARSERINTEROP_TA4651E220A7C199CFEB91E9B6FD3CB183C6C0954_H



// System.Void YoloRuntime.BoundingBox::.ctor()
extern "C" IL2CPP_METHOD_ATTR void BoundingBox__ctor_mF91EB45114F7548B304C39AEE5856A3850C2FD65 (BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E * __this, const RuntimeMethod* method);
// System.Void YoloRuntime.WinMlParserInterop::.ctor()
extern "C" IL2CPP_METHOD_ATTR void WinMlParserInterop__ctor_m6FE5ED430970000CE8F87F9CACBA11E12A1AD3BD (WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954 * __this, const RuntimeMethod* method);

// Factory for YoloRuntime.BoundingBox
struct BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E_Factory IL2CPP_FINAL : il2cpp::vm::ActivationFactoryBase<BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E_Factory>
{
	virtual il2cpp_hresult_t STDCALL ActivateInstance(Il2CppIInspectable** comReturnValue) IL2CPP_OVERRIDE
	{
		static bool s_Il2CppMethodInitialized;
		if (!s_Il2CppMethodInitialized)
		{
			il2cpp_codegen_initialize_method (BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E_Factory_ActivateInstance_MetadataUsageId);
			s_Il2CppMethodInitialized = true;
		}
		il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

		// Managed method invocation
		RuntimeObject * returnValue;
		try
		{
			BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E * managedInstance = (BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E*)il2cpp_codegen_object_new(BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E_il2cpp_TypeInfo_var);
			BoundingBox__ctor_mF91EB45114F7548B304C39AEE5856A3850C2FD65(managedInstance, NULL);
			returnValue = managedInstance;
		}
		catch (const Il2CppExceptionWrapper& ex)
		{
			memset(comReturnValue, 0, sizeof(*comReturnValue));
			String_t* exceptionStr = NULL;
			try
			{
				exceptionStr = VirtFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, ex.ex);
			}
			catch (const Il2CppExceptionWrapper&)
			{
				exceptionStr = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->get_Empty_5();
			}
			il2cpp_codegen_store_exception_info(ex.ex, exceptionStr);
			return ex.ex->hresult;
		}

		// Marshaling of return value back from managed representation
		Il2CppIInspectable* _returnValue_marshaled = NULL;
		if (returnValue != NULL)
		{
			if (il2cpp_codegen_is_import_or_windows_runtime(returnValue))
			{
				_returnValue_marshaled = il2cpp_codegen_com_query_interface<Il2CppIInspectable>(static_cast<Il2CppComObject*>(returnValue));
				(_returnValue_marshaled)->AddRef();
			}
			else
			{
				_returnValue_marshaled = il2cpp_codegen_com_get_or_create_ccw<Il2CppIInspectable>(returnValue);
			}
		}
		else
		{
			_returnValue_marshaled = NULL;
		}

		*comReturnValue = _returnValue_marshaled;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL QueryInterface(const Il2CppGuid& iid, void** object) IL2CPP_OVERRIDE
	{
		if (::memcmp(&iid, &Il2CppIUnknown::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIInspectable::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIAgileObject::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = GetIdentity();
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIActivationFactory::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIActivationFactory*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIMarshal::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIMarshal*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		*object = NULL;
		return IL2CPP_E_NOINTERFACE;
	}

	virtual uint32_t STDCALL AddRef() IL2CPP_OVERRIDE
	{
		return AddRefImpl();
	}

	virtual uint32_t STDCALL Release() IL2CPP_OVERRIDE
	{
		return ReleaseImpl();
	}

	virtual il2cpp_hresult_t STDCALL GetIids(uint32_t* iidCount, Il2CppGuid** iids) IL2CPP_OVERRIDE
	{
		Il2CppGuid* interfaceIds = il2cpp_codegen_marshal_allocate_array<Il2CppGuid>(1);
		interfaceIds[0] = Il2CppIActivationFactory::IID;

		*iidCount = 1;
		*iids = interfaceIds;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL GetRuntimeClassName(Il2CppHString* className) IL2CPP_OVERRIDE
	{
		return GetRuntimeClassNameImpl(className);
	}

	virtual il2cpp_hresult_t STDCALL GetTrustLevel(int32_t* trustLevel) IL2CPP_OVERRIDE
	{
		return ComObjectBase::GetTrustLevel(trustLevel);
	}
};
Il2CppIActivationFactory* CreateWindowsRuntimeFactoryFor_BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E()
{
	return static_cast<Il2CppIActivationFactory*>(BoundingBox_t2E5DFF459EA3ECEDB5E8DE431C94FD6D7381676E_Factory::__CreateInstance());
}

// Factory for YoloRuntime.WinMlParserInterop
struct WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954_Factory IL2CPP_FINAL : il2cpp::vm::ActivationFactoryBase<WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954_Factory>
{
	virtual il2cpp_hresult_t STDCALL ActivateInstance(Il2CppIInspectable** comReturnValue) IL2CPP_OVERRIDE
	{
		static bool s_Il2CppMethodInitialized;
		if (!s_Il2CppMethodInitialized)
		{
			il2cpp_codegen_initialize_method (WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954_Factory_ActivateInstance_MetadataUsageId);
			s_Il2CppMethodInitialized = true;
		}
		il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

		// Managed method invocation
		RuntimeObject * returnValue;
		try
		{
			WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954 * managedInstance = (WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954*)il2cpp_codegen_object_new(WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954_il2cpp_TypeInfo_var);
			WinMlParserInterop__ctor_m6FE5ED430970000CE8F87F9CACBA11E12A1AD3BD(managedInstance, NULL);
			returnValue = managedInstance;
		}
		catch (const Il2CppExceptionWrapper& ex)
		{
			memset(comReturnValue, 0, sizeof(*comReturnValue));
			String_t* exceptionStr = NULL;
			try
			{
				exceptionStr = VirtFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, ex.ex);
			}
			catch (const Il2CppExceptionWrapper&)
			{
				exceptionStr = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->get_Empty_5();
			}
			il2cpp_codegen_store_exception_info(ex.ex, exceptionStr);
			return ex.ex->hresult;
		}

		// Marshaling of return value back from managed representation
		Il2CppIInspectable* _returnValue_marshaled = NULL;
		if (returnValue != NULL)
		{
			if (il2cpp_codegen_is_import_or_windows_runtime(returnValue))
			{
				_returnValue_marshaled = il2cpp_codegen_com_query_interface<Il2CppIInspectable>(static_cast<Il2CppComObject*>(returnValue));
				(_returnValue_marshaled)->AddRef();
			}
			else
			{
				_returnValue_marshaled = il2cpp_codegen_com_get_or_create_ccw<Il2CppIInspectable>(returnValue);
			}
		}
		else
		{
			_returnValue_marshaled = NULL;
		}

		*comReturnValue = _returnValue_marshaled;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL QueryInterface(const Il2CppGuid& iid, void** object) IL2CPP_OVERRIDE
	{
		if (::memcmp(&iid, &Il2CppIUnknown::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIInspectable::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIAgileObject::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = GetIdentity();
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIActivationFactory::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIActivationFactory*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIMarshal::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIMarshal*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		*object = NULL;
		return IL2CPP_E_NOINTERFACE;
	}

	virtual uint32_t STDCALL AddRef() IL2CPP_OVERRIDE
	{
		return AddRefImpl();
	}

	virtual uint32_t STDCALL Release() IL2CPP_OVERRIDE
	{
		return ReleaseImpl();
	}

	virtual il2cpp_hresult_t STDCALL GetIids(uint32_t* iidCount, Il2CppGuid** iids) IL2CPP_OVERRIDE
	{
		Il2CppGuid* interfaceIds = il2cpp_codegen_marshal_allocate_array<Il2CppGuid>(1);
		interfaceIds[0] = Il2CppIActivationFactory::IID;

		*iidCount = 1;
		*iids = interfaceIds;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL GetRuntimeClassName(Il2CppHString* className) IL2CPP_OVERRIDE
	{
		return GetRuntimeClassNameImpl(className);
	}

	virtual il2cpp_hresult_t STDCALL GetTrustLevel(int32_t* trustLevel) IL2CPP_OVERRIDE
	{
		return ComObjectBase::GetTrustLevel(trustLevel);
	}
};
Il2CppIActivationFactory* CreateWindowsRuntimeFactoryFor_WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954()
{
	return static_cast<Il2CppIActivationFactory*>(WinMlParserInterop_tA4651E220A7C199CFEB91E9B6FD3CB183C6C0954_Factory::__CreateInstance());
}
