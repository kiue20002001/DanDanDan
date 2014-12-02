//
//  Player.cpp
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//  tag showPlayer 100番台を使用
//player:tag100
//うえ:tag 101
//ひだり:tag 102
//みぎ:tag 103
//した:tag 104
//  tag movePlayer 200番台を使用
//うえ:tag 201
//ひだり:tag 202
//みぎ:tag 203
//した:tag 204

#include "DanDan_First.h"
USING_NS_CC;
void DanDan::Dancing(int TagNumber)
{
    
    //拡大のアクション
    CCActionInterval* scaleAction = CCScaleBy::create(Time, Scale);
    //縮小のアクション
    CCActionInterval* scaleAction2 = CCScaleBy::create(Time,1./Scale);
    //拡大->縮小の順番にアクションを並べる
    CCSequence* sequence = CCSequence::create(scaleAction, scaleAction2, NULL);
    //無限リピート
    CCRepeat* repeat = CCRepeat::create(sequence, -1);
    //開始！
    getChildByTag(TagNumber)->runAction(repeat);
}

void DanDan::Dancing_Effect(){
    //十字キーを踊らす
    DanDan::Dancing(101);
    DanDan::Dancing(102);
    DanDan::Dancing(103);
    DanDan::Dancing(104);
    //十字キーを踊らす
}
