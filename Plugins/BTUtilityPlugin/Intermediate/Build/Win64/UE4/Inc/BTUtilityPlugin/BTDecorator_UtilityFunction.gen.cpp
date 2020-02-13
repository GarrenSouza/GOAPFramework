// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BTUtilityPlugin/Public/Decorators/BTDecorator_UtilityFunction.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTDecorator_UtilityFunction() {}
// Cross Module References
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityFunction_NoRegister();
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityFunction();
	AIMODULE_API UClass* Z_Construct_UClass_UBTDecorator();
	UPackage* Z_Construct_UPackage__Script_BTUtilityPlugin();
// End Cross Module References
	void UBTDecorator_UtilityFunction::StaticRegisterNativesUBTDecorator_UtilityFunction()
	{
	}
	UClass* Z_Construct_UClass_UBTDecorator_UtilityFunction_NoRegister()
	{
		return UBTDecorator_UtilityFunction::StaticClass();
	}
	struct Z_Construct_UClass_UBTDecorator_UtilityFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTDecorator_UtilityFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTDecorator,
		(UObject* (*)())Z_Construct_UPackage__Script_BTUtilityPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_UtilityFunction_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Condition" },
		{ "IncludePath", "Decorators/BTDecorator_UtilityFunction.h" },
		{ "ModuleRelativePath", "Public/Decorators/BTDecorator_UtilityFunction.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "Utility functions are responsible for providing a utility value for their associated node whenever the\nparent utility selector requests it." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTDecorator_UtilityFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTDecorator_UtilityFunction>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBTDecorator_UtilityFunction_Statics::ClassParams = {
		&UBTDecorator_UtilityFunction::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A1u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UBTDecorator_UtilityFunction_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityFunction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBTDecorator_UtilityFunction()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBTDecorator_UtilityFunction_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBTDecorator_UtilityFunction, 1335391328);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBTDecorator_UtilityFunction(Z_Construct_UClass_UBTDecorator_UtilityFunction, &UBTDecorator_UtilityFunction::StaticClass, TEXT("/Script/BTUtilityPlugin"), TEXT("UBTDecorator_UtilityFunction"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTDecorator_UtilityFunction);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
