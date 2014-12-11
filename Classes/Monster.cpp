#include "DanDan_First.h"
USING_NS_CC;

//tag 300番台
void DanDan::createMonster(){
    for(int x=0;x<10;x++){
        for(int y=0;y<10;y++){
            MonsterDate[x][y]=true;
        }
    }
    while(1){
        srand((unsigned int)time(NULL));
        //0から9までランダム
//        MonsterX= rand()%9;
//        MonsterY= rand()%9;
        MonsterX= 5;
        MonsterY= 4;
        if((MonsterX!=PlayerX)||(MonsterY!=PlayerY)){
            if(MapDate[MonsterX][MonsterY]){
                log("MonsterX=%d:MonsterY=%d",MonsterX,MonsterY);
                break;
            }
        }
    }
    MonsterDate[MonsterX][MonsterY]=false;
    showMonster();
    moveMonster(1,1);
    shiftMonster(MonsterX-PlayerX,MonsterY-PlayerY,0);
}
void DanDan::shiftMonster(int x,int y,double MonsterTime)
{
    CCActionInterval* scaleAction = CCMoveBy::create(MonsterTime, ccp(DanSize*x, DanSize*y));
    CCSequence* sequence = CCSequence::create(scaleAction, NULL);
    CCRepeat* repeat = CCRepeat::create(sequence, 1);
    getChildByTag(300)->runAction(repeat);
}

void DanDan::showMonster()
{
    //player:tag100
    auto Monster = CCSprite::create("defo01.png",DanCell);
    Monster->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(Monster);
    Monster -> setTag(300);
}

void DanDan::moveMonster(int animeNumber,int moveNumber)
{
    std::string Anime_Str = "Slime00_Anime_";
    Anime_Str += cocos2d::StringUtils::toString<int>(animeNumber);
    Anime_Str += ".plist";
    std::string Move_Str = "Slime00_";
    Move_Str += cocos2d::StringUtils::toString<int>(moveNumber);
    
    
    CCAnimationCache* cache = CCAnimationCache::sharedAnimationCache();
    cache->addAnimationsWithFile(Anime_Str);
    CCAnimation* animationD = cache->animationByName(Move_Str);
    CCAnimate* actionD = CCAnimate::create(animationD);
    CCSprite* player = (CCSprite*)this->getChildByTag(300);
    player->runAction(actionD);
    actionD->setTag(301);
}

