#ifndef _NAKADE_H_
#define _NAKADE_H_

#include "GoBoard.h"

////////////
//  定数  //
////////////

const int NOT_NAKADE = -1;

const int NAKADE_QUEUE_SIZE = 30;

//////////////
//  構造体  //
//////////////
typedef struct {
  int pos[NAKADE_QUEUE_SIZE];
  int head, tail;
} nakade_queue_t;

////////////
//  関数  //
////////////
// ナカデのハッシュの初期設定
void InitializeNakadeHash( void );

// 自己アタリがナカデの形になっているか(シミュレーション用)
bool IsNakadeSelfAtari( game_info_t *game, int pos, int color );

// 自己アタリがナカデの形になっているか(UCT用)
bool IsUctNakadeSelfAtari( game_info_t *game, int pos, int color );

// 直前の手で囲ったエリアにナカデの急所があるかを確認
// ナカデの急所があれば, その座標を
// なければ, -1を返す
void SearchNakade( game_info_t *game, int *nakade_num, int *nakade_pos );

// 直前の手で取られた石がナカデの形になっているかを確認
// ナカデの急所があれば, その座標を返す
// なければ, -1を返す
int CheckRemovedStoneNakade( game_info_t *game, int color );

#endif
