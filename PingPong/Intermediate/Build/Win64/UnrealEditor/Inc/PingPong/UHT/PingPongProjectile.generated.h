// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PingPongProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef PINGPONG_PingPongProjectile_generated_h
#error "PingPongProjectile.generated.h already included, missing '#pragma once' in PingPongProjectile.h"
#endif
#define PINGPONG_PingPongProjectile_generated_h

#define FID_PingPong_Source_PingPong_PingPongProjectile_h_15_SPARSE_DATA
#define FID_PingPong_Source_PingPong_PingPongProjectile_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_PingPong_Source_PingPong_PingPongProjectile_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_PingPong_Source_PingPong_PingPongProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FID_PingPong_Source_PingPong_PingPongProjectile_h_15_ACCESSORS
#define FID_PingPong_Source_PingPong_PingPongProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPingPongProjectile(); \
	friend struct Z_Construct_UClass_APingPongProjectile_Statics; \
public: \
	DECLARE_CLASS(APingPongProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PingPong"), NO_API) \
	DECLARE_SERIALIZER(APingPongProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_PingPong_Source_PingPong_PingPongProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APingPongProjectile(APingPongProjectile&&); \
	NO_API APingPongProjectile(const APingPongProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APingPongProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APingPongProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APingPongProjectile) \
	NO_API virtual ~APingPongProjectile();


#define FID_PingPong_Source_PingPong_PingPongProjectile_h_12_PROLOG
#define FID_PingPong_Source_PingPong_PingPongProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PingPong_Source_PingPong_PingPongProjectile_h_15_SPARSE_DATA \
	FID_PingPong_Source_PingPong_PingPongProjectile_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_PingPong_Source_PingPong_PingPongProjectile_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_PingPong_Source_PingPong_PingPongProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_PingPong_Source_PingPong_PingPongProjectile_h_15_ACCESSORS \
	FID_PingPong_Source_PingPong_PingPongProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_PingPong_Source_PingPong_PingPongProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PINGPONG_API UClass* StaticClass<class APingPongProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PingPong_Source_PingPong_PingPongProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
