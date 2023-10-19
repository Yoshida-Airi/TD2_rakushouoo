#include "Player.h"
#include "Player.h"

Player::~Player()
{
}

/// <summary>
/// 初期化
/// </ summary>
void Player::Initialize(Model* model, Vector3 position)
{
	assert(model);
	model_ = model;
	
	input_ = Input::GetInstance();

	model_->Initialize("Resources", "cube.obj");

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.UpdateMatrix();
}

/// <summary>
/// 初期化
/// </ summary>
void Player::Update()
{// キャラクターの移動ベクトル
	move = { 0, 0, 0 };

	move.x += kCharacterSpeedX;
	move.y += kCharacterSpeedY;

	if (isHit) {
		move.y = 0;
		isHit = false;
	}

	if (isHit2) {
		kCharacterSpeedY = 0.2f;
		isHit2 = false;
	}

	// 押した方向で移動ベクトルを変更(左右)
	if (input_->PushKey(DIK_SPACE)) {
		move.y -= kCharacterSpeed;
	}



	// 座標移動(ベクトルの加算)
	worldTransform_.translation_.x += move.x;
	worldTransform_.translation_.y -= move.y;


	// ワールドトランスフォームの更新
	worldTransform_.UpdateMatrix();


}

/// <summary>
/// 初期化
/// </ summary>
void Player::Draw(ViewProjection viewProjection)
{
	model_->Draw(viewProjection, worldTransform_);
}
