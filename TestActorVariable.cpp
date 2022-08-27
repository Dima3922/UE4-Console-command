// Unreal Ferox tutorials


#include "TestActorVariable.h"


/**@brief Console Int32 variable for testing */
const TAutoConsoleVariable<int32> FeroxDebugInt(TEXT("Ferox.Debug.Int"), 0, TEXT("YOUR DEBUG TEST int32"));

/**@brief Console Float variable for testing */
const TAutoConsoleVariable<float> FeroxDebugFloat(TEXT("Ferox.Debug.Float"), 0, TEXT("YOUR DEBUG TEST float"));

/**@brief Console String variable for testing */
const TAutoConsoleVariable<FString> FeroxDebugFString(TEXT("Ferox.Debug.FString"), TEXT("None"), TEXT("YOUR DEBUG TEST FString"));



// Sets default values
ATestActorVariable::ATestActorVariable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActorVariable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActorVariable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (FeroxDebugInt.GetValueOnGameThread())
	{
	case 0:
		//0 by default, do nothing
		break;
	case 1:
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, TEXT("FeroxDebug INT: 1"));
		break;
	case 2:
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, TEXT("FeroxDebug INT: 2"));
		break;
	default:
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, TEXT("FeroxDebug Default"));
		break;
	}

	if(FeroxDebugFloat.GetValueOnGameThread() == 1.f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, TEXT("FeroxDebug Float: 1"));
	}

	if(FeroxDebugFString.GetValueOnGameThread() == "one")
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, TEXT("FeroxDebug FString: one"));
	}
}

