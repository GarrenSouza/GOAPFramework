// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BTUtilityPlugin/Public/Decorators/BTDecorator_UtilityBlackboard.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTDecorator_UtilityBlackboard() {}
// Cross Module References
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityBlackboard_NoRegister();
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityBlackboard();
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityFunction();
	UPackage* Z_Construct_UPackage__Script_BTUtilityPlugin();
	AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FBlackboardKeySelector();
// End Cross Module References
	void UBTDecorator_UtilityBlackboard::StaticRegisterNativesUBTDecorator_UtilityBlackboard()
	{
	}
	UClass* Z_Construct_UClass_UBTDecorator_UtilityBlackboard_NoRegister()
	{
		return UBTDecorator_UtilityBlackboard::StaticClass();
	}
	struct Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UtilityValueKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UtilityValueKey;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTDecorator_UtilityFunction,
		(UObject* (*)())Z_Construct_UPackage__Script_BTUtilityPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::Class_MetaDataParams[] = {
		{ "Category", "Utility Functions" },
		{ "DisplayName", "Blackboard Utility" },
		{ "HideCategories", "Condition" },
		{ "IncludePath", "Decorators/BTDecorator_UtilityBlackboard.h" },
		{ "ModuleRelativePath", "Public/Decorators/BTDecorator_UtilityBlackboard.h" },
		{ "ToolTip", "Blackboard based utility function.\nThe associated node's utility value is specified via a blackboard key.\nThe key must be of type Float or Integer." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::NewProp_UtilityValueKey_MetaData[] = {
		{ "Category", "Blackboard" },
		{ "ModuleRelativePath", "Public/Decorators/BTDecorator_UtilityBlackboard.h" },
		{ "ToolTip", "blackboard key selector" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::NewProp_UtilityValueKey = { UE4CodeGen_Private::EPropertyClass::Struct, "UtilityValueKey", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000001, 1, nullptr, STRUCT_OFFSET(UBTDecorator_UtilityBlackboard, UtilityValueKey), Z_Construct_UScriptStruct_FBlackboardKeySelector, METADATA_PARAMS(Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::NewProp_UtilityValueKey_MetaData, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::NewProp_UtilityValueKey_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::NewProp_UtilityValueKey,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTDecorator_UtilityBlackboard>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::ClassParams = {
		&UBTDecorator_UtilityBlackboard::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBTDecorator_UtilityBlackboard()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBTDecorator_UtilityBlackboard_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBTDecorator_UtilityBlackboard, 1166896085);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBTDecorator_UtilityBlackboard(Z_Construct_UClass_UBTDecorator_UtilityBlackboard, &UBTDecorator_UtilityBlackboard::StaticClass, TEXT("/Script/BTUtilityPlugin"), TEXT("UBTDecorator_UtilityBlackboard"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTDecorator_UtilityBlackboard);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
