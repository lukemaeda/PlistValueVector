//
//  TopPlistScene.h
//  PlistValueVector
//
//  Created by MAEDAHAJIME on 2015/02/19.
//
//

#ifndef __PlistValueVector__TopPlistScene__
#define __PlistValueVector__TopPlistScene__

#include "cocos2d.h"

class TopPlistScene : public cocos2d::Layer
{
public:
    
    //初期化のメソッド
    virtual bool init();
    
    static cocos2d::Scene* createScene();
    
    // create()を使えるようにしている。
    CREATE_FUNC(TopPlistScene);
    
};

#endif /* defined(__PlistValueVector__TopPlistScene__) */
