//
//  TopPlistScene.cpp
//  PlistValueVector
//
//  Created by MAEDAHAJIME on 2015/02/19.
//
//

#include "TopPlistScene.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

using namespace std; // String*

Scene* TopPlistScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = TopPlistScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}

// 「INIT」初期化
bool TopPlistScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    //画面の座標関係の詳しい説明はここ http://www.cocos2d-x.org/wiki/Coordinate_System
    //画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();  //マルチレゾリューション対応がどうとか
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    //バックグランドカラー追加 第2引数は表示順
    this->addChild(background, 0);
    
    //////////////////////////////////////////////
    
    //タイトルを設置
    auto lbl_title = Label::createWithSystemFont("Info Plist", "arial", 100);
    lbl_title->setPosition(Point(origin.x + winSize.width/2,
                                 origin.y + winSize.height
                                 -lbl_title->getContentSize().height));
    this->addChild(lbl_title,1);
    
    //////////////////////////////////////////////
    
    // ValueVector 配列
    ValueVector vec = FileUtils::getInstance()->getValueVectorFromFile("data.plist");
    std::string vec_0 = vec.at(0).asString();
    std::string vec_1 = vec.at(1).asString();
    std::string vec_2 = vec.at(2).asString();
    std::string vec_3 = vec.at(3).asString();
    
    auto label1 = Label::createWithSystemFont(vec_0, "arial", 80);
    // label1を表示
    addChild(label1);
    // ラベルの位置
    label1->setPosition(Vec2(winSize.width/2, winSize.height/2 - 200)); // info2
    // ラベルの色:ホワイト
    label1->setColor(Color3B::WHITE);
    
    auto label2 = Label::createWithSystemFont(vec_1, "arial", 80);
    // label2を表示
    addChild(label2);
    // ラベルの位置
    label2->setPosition(Vec2(winSize.width/2, winSize.height/2 - 100)); // 2
    // ラベルの色:ホワイト
    label2->setColor(Color3B::WHITE);
    
    auto label3 = Label::createWithSystemFont(vec_2, "arial", 80);
    // label3を表示
    addChild(label3);
    // ラベルの位置
    label3->setPosition(Vec2(winSize.width/2, winSize.height/2)); // info1
    // ラベルの色:ホワイト
    label3->setColor(Color3B::WHITE);
    
    auto label4 = Label::createWithSystemFont(vec_3, "arial", 80);
    // label4を表示
    addChild(label4);
    // ラベルの位置
    label4->setPosition(Vec2(winSize.width/2, winSize.height/2 + 100)); // 1
    // ラベルの色:ホワイト
    label4->setColor(Color3B::WHITE);
    
    //////////////////////////////////////////////
    
    return true;
}
