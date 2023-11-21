// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "EnumAndStructs.h"
#include "CoreMinimal.h"

/**
 * 
 */
class PROJ2023_API Worker
{
public:
	Worker();
	~Worker();

	int32 workedId = -1;

	int32 workrate = 80;
	
	WorkType workType = WorkType::unassigned;
};
