// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BTUtilityPlugin/Public/Decorators/BTDecorator_UtilityConstant.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTDecorator_UtilityConstant() {}
// Cross Module References
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityConstant_NoRegister();
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityConstant();
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityFunction();
	UPackage* Z_Construct_UPackage__Script_BTUtilityPlugin();
// End Cross Module References
	void UBTDecorator_UtilityConstant::StaticRegisterNativesUBTDecorator_UtilityConstant()
	{
	}
	UClass* Z_Construct_UClass_UBTDecorator_UtilityConstant_NoRegister()
	{
		return UBTDecorator_UtilityConstant::StaticClass();
	}
	struct Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UtilityValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_UtilityValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTDecorator_UtilityFunction,
		(UObject* (*)())Z_Construct_UPackage__Script_BTUtilityPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::Class_MetaDataParams[] = {
		{ "Category", "Utility Functions" },
		{ "DisplayName", "Constant Utility" },
		{ "HideCategories", "Condition" },
		{ "IncludePath", "Decorators/BTDecorator_UtilityConstant.h" },
		{ "ModuleRelativePath", "Public/Decorators/BTDecorator_UtilityConstant.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "Constant utility function.\nThe associated node's utility value is specified as a constant value." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::NewProp_UtilityValue_MetaData[] = {
		{ "Category", "Utility" },
		{ "ModuleRelativePath", "Public/Decorators/BTDecorator_UtilityConstant.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::NewProp_UtilityValue = { UE4CodeGen_Private::EPropertyClass::Float, "UtilityValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UBTDecorator_UtilityConstant, UtilityValue), METADATA_PARAMS(Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::NewProp_UtilityValue_MetaData, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::NewProp_UtilityValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::NewProp_UtilityValue,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTDecorator_UtilityConstant>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::ClassParams = {
		&UBTDecorator_UtilityConstant::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBTDecorator_UtilityConstant()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBTDecorator_UtilityConstant_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBTDecorator_UtilityConstant, 1387383133);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBTDecorator_UtilityConstant(Z_Construct_UClass_UBTDecorator_UtilityConstant, &UBTDecorator_UtilityConstant::StaticClass, TEXT("/Script/BTUtilityPlugin"), TEXT("UBTDecorator_UtilityConstant"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTDecorator_UtilityConstant);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
