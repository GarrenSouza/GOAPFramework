// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AAIController;
class APawn;
#ifdef BTUTILITYPLUGIN_BTDecorator_UtilityBlueprintBase_generated_h
#error "BTDecorator_UtilityBlueprintBase.generated.h already included, missing '#pragma once' in BTDecorator_UtilityBlueprintBase.h"
#endif
#define BTUTILITYPLUGIN_BTDecorator_UtilityBlueprintBase_generated_h

#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_RPC_WRAPPERS
#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_EVENT_PARMS \
	struct BTDecorator_UtilityBlueprintBase_eventCalculateUtility_Parms \
	{ \
		AAIController* OwnerController; \
		APawn* ControlledPawn; \
		float ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		BTDecorator_UtilityBlueprintBase_eventCalculateUtility_Parms() \
			: ReturnValue(0) \
		{ \
		} \
	};


#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_CALLBACK_WRAPPERS
#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBTDecorator_UtilityBlueprintBase(); \
	friend struct Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics; \
public: \
	DECLARE_CLASS(UBTDecorator_UtilityBlueprintBase, UBTDecorator_UtilityFunction, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/BTUtilityPlugin"), NO_API) \
	DECLARE_SERIALIZER(UBTDecorator_UtilityBlueprintBase)


#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUBTDecorator_UtilityBlueprintBase(); \
	friend struct Z_Construct_UClass_UBTDecorator_UtilityBlueprintBase_Statics; \
public: \
	DECLARE_CLASS(UBTDecorator_UtilityBlueprintBase, UBTDecorator_UtilityFunction, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/BTUtilityPlugin"), NO_API) \
	DECLARE_SERIALIZER(UBTDecorator_UtilityBlueprintBase)


#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBTDecorator_UtilityBlueprintBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBTDecorator_UtilityBlueprintBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBTDecorator_UtilityBlueprintBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBTDecorator_UtilityBlueprintBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBTDecorator_UtilityBlueprintBase(UBTDecorator_UtilityBlueprintBase&&); \
	NO_API UBTDecorator_UtilityBlueprintBase(const UBTDecorator_UtilityBlueprintBase&); \
public:


#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBTDecorator_UtilityBlueprintBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBTDecorator_UtilityBlueprintBase(UBTDecorator_UtilityBlueprintBase&&); \
	NO_API UBTDecorator_UtilityBlueprintBase(const UBTDecorator_UtilityBlueprintBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBTDecorator_UtilityBlueprintBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBTDecorator_UtilityBlueprintBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBTDecorator_UtilityBlueprintBase)


#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__AIOwner() { return STRUCT_OFFSET(UBTDecorator_UtilityBlueprintBase, AIOwner); } \
	FORCEINLINE static uint32 __PPO__ActorOwner() { return STRUCT_OFFSET(UBTDecorator_UtilityBlueprintBase, ActorOwner); }


#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_13_PROLOG \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_EVENT_PARMS


#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_PRIVATE_PROPERTY_OFFSET \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_RPC_WRAPPERS \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_CALLBACK_WRAPPERS \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_INCLASS \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_PRIVATE_PROPERTY_OFFSET \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_CALLBACK_WRAPPERS \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_INCLASS_NO_PURE_DECLS \
	GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h_16_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class BTDecorator_UtilityBlueprintBase."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GOAPFramework_Plugins_BTUtilityPlugin_Source_BTUtilityPlugin_Public_Decorators_BTDecorator_UtilityBlueprintBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
