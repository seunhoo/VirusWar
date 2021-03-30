#pragma once

typedef struct D3DXVECTOR2 Vec2;
typedef struct D3DXMATRIX Matrix;

template<class T>
inline void SafeDelete(T*&x);

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<stdlib.h>
#include<list>
#include<map>
#include<stdio.h>
#include<mmsystem.h>
#include<vector>
#include<string>
#include<time.h>
#include<iostream>


#include"Singleton.h"
#include"App.h"
#include"Renderer.h"
#include"Input.h"
#include"Scene.h"
#include"SceneDirector.h"
#include"Object.h"
#include"ObjectMgr.h"
#include"TextMgr.h"
#include"Texture.h"
#include"ResourceMgr.h"
#include"Sprite.h"
#include"SoundMgr.h"
#include"CollideMgr.h"
#include"LineMgr.h"
#include"TextMgr.h"

template<class T>
inline void SafeDelete(T*& x)
{
	delete x;
	x = static_cast<T*>(0);
}
