#pragma once
#include"Model.h"
#include"Vector3.h"
#include"Input.h"
#include<cassert>
#include"WorldTransform.h"
class Player
{
public:
	~Player();

	/// <summary>
	/// 初期化
	/// </ summary>
	void Initialize(Model* model,Vector3 position);
	
	/// <summary>
	/// 初期化
	/// </ summary>
	void Update();

	/// <summary>
	/// 初期化
	/// </ summary>
	void Draw(ViewProjection viewProjection);

private:

	Model* model_ = nullptr;
	Input* input_ = nullptr;
	Vector2 speed_ = {};
	WorldTransform worldTransform_;

	// キャラクターの移動速さ
	float kCharacterSpeedX = 0.2f;
	float kCharacterSpeedY = 0.2f;

	float kCharacterSpeed = 0.4f;

	bool isHit = false;
	bool isHit2 = false;

	Vector3 move;
};

