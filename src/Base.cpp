#include "Base.h"

Base::Base(ofxTuioObject * _tuioObject){
    //オブジェクトのIDで条件分岐
    if(_tuioObject->getFiducialId()<){
        index=1;
    if(_tuioObject->getFiducialId()<SAMPLE_NUM){
        FID=_tuioObject->getFiducialId();
        sample=new Sample(_tuioObject);
        index=1;//上から順番に番号をふる
    }

}
//デフォルトコンストラクタ(必ず上のコンストラクタを呼ぶこと)
Base::Base(){
    //必ずここでインスタンスさくせい
    sample=new Sample();
}

//マーカーIDの取得
int Base::getFid(){
    return FID;
}
//描画処理
void Base::draw(){
    //indexに振り分けた番号でそのオブジェクトのdraw()を呼ぶ
    switch(index){
        case 1:
            sample.draw();
            break;
    }
}
//状態の更新
void Base::update(ofxTuioObject * _tuioObject){
    //draw()と同様に
    switch(index){
        case 1:
            sample.update(_tuioObject);
            break;
    }
}
//タッチ時に必ず呼ばれる
void Base::touchAction(ofxTuioCursor * _tuioCursor){
        switch(index){
            case 1:
                sample.touchAction(_tuioCursor);
                break;
        }
}
//消去時に呼ばれる
void Base::destroy(){
        switch(index){
            case 1:
                sample.destroy();
                break;
        }
}

