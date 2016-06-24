#include "CocosAppDelegate.h"
#include "audio/include/SimpleAudioEngine.h"
#include "cocos2d.h"


using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

CocosAppDelegate::CocosAppDelegate()
{
}

CocosAppDelegate::~CocosAppDelegate()
{
    SimpleAudioEngine::end();

#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
    // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
    RuntimeEngine::getInstance()->end();
#endif

}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void CocosAppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool CocosAppDelegate::applicationDidFinishLaunching()
{

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void CocosAppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void CocosAppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
