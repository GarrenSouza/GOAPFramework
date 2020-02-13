// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BTUtilityPlugin/Public/Composites/BTComposite_Utility.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTComposite_Utility() {}
// Cross Module References
	BTUTILITYPLUGIN_API UEnum* Z_Construct_UEnum_BTUtilityPlugin_EUtilitySelectionMethod();
	UPackage* Z_Construct_UPackage__Script_BTUtilityPlugin();
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTComposite_Utility_NoRegister();
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTComposite_Utility();
	AIMODULE_API UClass* Z_Construct_UClass_UBTCompositeNode();
// End Cross Module References
	static UEnum* EUtilitySelectionMethod_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_BTUtilityPlugin_EUtilitySelectionMethod, Z_Construct_UPackage__Script_BTUtilityPlugin(), TEXT("EUtilitySelectionMethod"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EUtilitySelectionMethod(EUtilitySelectionMethod_StaticEnum, TEXT("/Script/BTUtilityPlugin"), TEXT("EUtilitySelectionMethod"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_BTUtilityPlugin_EUtilitySelectionMethod_CRC() { return 4030753060U; }
	UEnum* Z_Construct_UEnum_BTUtilityPlugin_EUtilitySelectionMethod()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_BTUtilityPlugin();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EUtilitySelectionMethod"), 0, Get_Z_Construct_UEnum_BTUtilityPlugin_EUtilitySelectionMethod_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EUtilitySelectionMethod::Priority", (int64)EUtilitySelectionMethod::Priority },
				{ "EUtilitySelectionMethod::Proportional", (int64)EUtilitySelectionMethod::Proportional },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Composites/BTComposite_Utility.h" },
				{ "Priority.ToolTip", "The child with the highest utility value is always chosen" },
				{ "Proportional.ToolTip", "Selection probability is proportional to utility value" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_BTUtilityPlugin,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EUtilitySelectionMethod",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EUtilitySelectionMethod",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UBTComposite_Utility::StaticRegisterNativesUBTComposite_Utility()
	{
	}
	UClass* Z_Construct_UClass_UBTComposite_Utility_NoRegister()
	{
		return UBTComposite_Utility::StaticClass();
	}
	struct Z_Construct_UClass_UBTComposite_Utility_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelectionMethod_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_SelectionMethod;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SelectionMethod_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTComposite_Utility_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTCompositeNode,
		(UObject* (*)())Z_Construct_UPackage__Script_BTUtilityPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTComposite_Utility_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Composites/BTComposite_Utility.h" },
		{ "ModuleRelativePath", "Public/Composites/BTComposite_Utility.h" },
		{ "ToolTip", "Utility selector node.\nUtility Nodes choose at most one of their children to execute. The choice made is a function of the utility values of the children.\nA Utility Node will succeed if its chosen child succeeds, and will fail if its chosen child fails or if no child could be executed." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTComposite_Utility_Statics::NewProp_SelectionMethod_MetaData[] = {
		{ "Category", "Utility" },
		{ "ModuleRelativePath", "Public/Composites/BTComposite_Utility.h" },
		{ "ToolTip", "Method used to determine child selection based on utility values" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UBTComposite_Utility_Statics::NewProp_SelectionMethod = { UE4CodeGen_Private::EPropertyClass::Enum, "SelectionMethod", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UBTComposite_Utility, SelectionMethod), Z_Construct_UEnum_BTUtilityPlugin_EUtilitySelectionMethod, METADATA_PARAMS(Z_Construct_UClass_UBTComposite_Utility_Statics::NewProp_SelectionMethod_MetaData, ARRAY_COUNT(Z_Construct_UClass_UBTComposite_Utility_Statics::NewProp_SelectionMethod_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UBTComposite_Utility_Statics::NewProp_SelectionMethod_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTComposite_Utility_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTComposite_Utility_Statics::NewProp_SelectionMethod,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTComposite_Utility_Statics::NewProp_SelectionMethod_Underlying,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTComposite_Utility_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTComposite_Utility>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBTComposite_Utility_Statics::ClassParams = {
		&UBTComposite_Utility::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UBTComposite_Utility_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UBTComposite_Utility_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UBTComposite_Utility_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UBTComposite_Utility_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBTComposite_Utility()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBTComposite_Utility_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBTComposite_Utility, 2929574122);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBTComposite_Utility(Z_Construct_UClass_UBTComposite_Utility, &UBTComposite_Utility::StaticClass, TEXT("/Script/BTUtilityPlugin"), TEXT("UBTComposite_Utility"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTComposite_Utility);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
