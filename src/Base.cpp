#include "Base.h"

Base::Base(ofxTuioObject * _tuioObject){
    //オブジェクトのIDで条件分岐
<<<<<<< HEAD
    if(_tuioObject->getFiducialId()<){
        index=1;
=======
    if(_tuioObject->getFiducialId()<SAMPLE_NUM){
        FID=_tuioObject->getFiducialId();
        sample=new Sample(_tuioObject);
        index=1;//上から順番に番号をふる
>>>>>>> origin/master
    }

}
//デフォルトコンストラクタ(必ず上のコンストラクタを呼ぶこと)
Base::Base(){
    //必ずここでインスタンスを作成
<<<<<<< HEAD
=======
    sample=new Sample();
>>>>>>> origin/master
}

//マーカーIDの取得
int Base::getFid(){
    return FID;
}
//描画処理
void Base::draw(){
    //indexに振り分けた番号でそのオブジェクトのdraw()を呼ぶ
    switch(index){
<<<<<<< HEAD
=======
        case 1:
            sample.draw();
            break;
>>>>>>> origin/master
    }
}
//状態の更新
void Base::update(ofxTuioObject * _tuioObject){
    //draw()と同様に
    switch(index){
<<<<<<< HEAD
=======
        case 1:
            sample.update(_tuioObject);
            break;
>>>>>>> origin/master
    }
}
//タッチ時に必ず呼ばれる
void Base::touchAction(ofxTuioCursor * _tuioCursor){
        switch(index){
<<<<<<< HEAD
=======
            case 1:
                sample.touchAction(_tuioCursor);
                break;
>>>>>>> origin/master
        }
}
//消去時に呼ばれる
void Base::destroy(){
        switch(index){
<<<<<<< HEAD
=======
            case 1:
                sample.destroy();
                break;
>>>>>>> origin/master
        }
}

