// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PingPongCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PINGPONG_PingPongCharacter_generated_h
#error "PingPongCharacter.generated.h already included, missing '#pragma once' in PingPongCharacter.h"
#endif
#define PINGPONG_PingPongCharacter_generated_h

#define FID_PingPong_Source_PingPong_PingPongCharacter_h_22_SPARSE_DATA
#define FID_PingPong_Source_PingPong_PingPongCharacter_h_22_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_PingPong_Source_PingPong_PingPongCharacter_h_22_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_PingPong_Source_PingPong_PingPongCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetHasRifle); \
	DECLARE_FUNCTION(execSetHasRifle);


#define FID_PingPong_Source_PingPong_PingPongCharacter_h_22_ACCESSORS
#define FID_PingPong_Source_PingPong_PingPongCharacter_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPingPongCharacter(); \
	friend struct Z_Construct_UClass_APingPongCharacter_Statics; \
public: \
	DECLARE_CLASS(APingPongCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PingPong"), NO_API) \
	DECLARE_SERIALIZER(APingPongCharacter)


#define FID_PingPong_Source_PingPong_PingPongCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APingPongCharacter(APingPongCharacter&&); \
	NO_API APingPongCharacter(const APingPongCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APingPongCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APingPongCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APingPongCharacter) \
	NO_API virtual ~APingPongCharacter();


#define FID_PingPong_Source_PingPong_PingPongCharacter_h_19_PROLOG
#define FID_PingPong_Source_PingPong_PingPongCharacter_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PingPong_Source_PingPong_PingPongCharacter_h_22_SPARSE_DATA \
	FID_PingPong_Source_PingPong_PingPongCharacter_h_22_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_PingPong_Source_PingPong_PingPongCharacter_h_22_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_PingPong_Source_PingPong_PingPongCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_PingPong_Source_PingPong_PingPongCharacter_h_22_ACCESSORS \
	FID_PingPong_Source_PingPong_PingPongCharacter_h_22_INCLASS_NO_PURE_DECLS \
	FID_PingPong_Source_PingPong_PingPongCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PINGPONG_API UClass* StaticClass<class APingPongCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PingPong_Source_PingPong_PingPongCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
