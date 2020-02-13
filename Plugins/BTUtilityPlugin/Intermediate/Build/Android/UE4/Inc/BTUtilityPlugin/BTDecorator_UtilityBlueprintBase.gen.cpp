// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BTUtilityPlugin/Public/Decorators/BTDecorator_UtilityBlueprintBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTDecorator_UtilityBlueprintBase() {}
// Cross Module References
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_NoRegister();
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase();
	BTUTILITYPLUGIN_API UClass* Z_Construct_UClass_UBTDecorator_UtilityFunction();
	UPackage* Z_Construct_UPackage__Script_BTUtilityPlugin();
	BTUTILITYPLUGIN_API UFunction* Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	static FName NAME_UBTDecorator_UtilityBlueprintBase_CalculateUtility = FName(TEXT("CalculateUtility"));
	float UBTDecorator_UtilityBlueprintBase::CalculateUtility(AAIController* OwnerController, APawn* ControlledPawn) const
	{
		BTDecorator_UtilityBlueprintBase_eventCalculateUtility_Parms Parms;
		Parms.OwnerController=OwnerController;
		Parms.ControlledPawn=ControlledPawn;
		const_cast<UBTDecorator_UtilityBlueprintBase*>(this)->ProcessEvent(FindFunctionChecked(NAME_UBTDecorator_UtilityBlueprintBase_CalculateUtility),&Parms);
		return Parms.ReturnValue;
	}
	void UBTDecorator_UtilityBlueprintBase::StaticRegisterNativesUBTDecorator_UtilityBlueprintBase()
	{
	}
	struct Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ControlledPawn;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OwnerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(BTDecorator_UtilityBlueprintBase_eventCalculateUtility_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::NewProp_ControlledPawn = { UE4CodeGen_Private::EPropertyClass::Object, "ControlledPawn", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BTDecorator_UtilityBlueprintBase_eventCalculateUtility_Parms, ControlledPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::NewProp_OwnerController = { UE4CodeGen_Private::EPropertyClass::Object, "OwnerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BTDecorator_UtilityBlueprintBase_eventCalculateUtility_Parms, OwnerController), Z_Construct_UClass_AAIController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::NewProp_ControlledPawn,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::NewProp_OwnerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::Function_MetaDataParams[] = {
		{ "Category", "Utility" },
		{ "ModuleRelativePath", "Public/Decorators/BTDecorator_UtilityBlueprintBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase, "CalculateUtility", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x48080800, sizeof(BTDecorator_UtilityBlueprintBase_eventCalculateUtility_Parms), Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_NoRegister()
	{
		return UBTDecorator_UtilityBlueprintBase::StaticClass();
	}
	struct Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorOwner_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorOwner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AIOwner_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AIOwner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTDecorator_UtilityFunction,
		(UObject* (*)())Z_Construct_UPackage__Script_BTUtilityPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UBTDecorator_UtilityBlueprintBase_CalculateUtility, "CalculateUtility" }, // 3335835991
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Condition" },
		{ "IncludePath", "Decorators/BTDecorator_UtilityBlueprintBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Decorators/BTDecorator_UtilityBlueprintBase.h" },
		{ "ToolTip", "@TODO: Look into what the purpose is of PropertyData in the other blueprint base classes, may need to\nduplicate it." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::NewProp_ActorOwner_MetaData[] = {
		{ "ModuleRelativePath", "Public/Decorators/BTDecorator_UtilityBlueprintBase.h" },
		{ "ToolTip", "Cached actor owner of BehaviorTreeComponent." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::NewProp_ActorOwner = { UE4CodeGen_Private::EPropertyClass::Object, "ActorOwner", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000002000, 1, nullptr, STRUCT_OFFSET(UBTDecorator_UtilityBlueprintBase, ActorOwner), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::NewProp_ActorOwner_MetaData, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::NewProp_ActorOwner_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::NewProp_AIOwner_MetaData[] = {
		{ "ModuleRelativePath", "Public/Decorators/BTDecorator_UtilityBlueprintBase.h" },
		{ "ToolTip", "Cached AIController owner of BehaviorTreeComponent." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::NewProp_AIOwner = { UE4CodeGen_Private::EPropertyClass::Object, "AIOwner", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000002000, 1, nullptr, STRUCT_OFFSET(UBTDecorator_UtilityBlueprintBase, AIOwner), Z_Construct_UClass_AAIController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::NewProp_AIOwner_MetaData, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::NewProp_AIOwner_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::NewProp_ActorOwner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::NewProp_AIOwner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTDecorator_UtilityBlueprintBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::ClassParams = {
		&UBTDecorator_UtilityBlueprintBase::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A1u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBTDecorator_UtilityBlueprintBase, 252521963);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBTDecorator_UtilityBlueprintBase(Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase, &UBTDecorator_UtilityBlueprintBase::StaticClass, TEXT("/Script/BTUtilityPlugin"), TEXT("UBTDecorator_UtilityBlueprintBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTDecorator_UtilityBlueprintBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
