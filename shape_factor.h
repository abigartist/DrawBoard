#pragma once



#include "mouse_event.h"
#include <vector>
#include <queue>

#define end -1

using std::queue;
using std::vector;

class ShapeFactor
{
public:
	virtual void Paint() = 0;   //��ͼ,ע�������WM_PAINT��ʹ��
	virtual void SetDC(HDC hdc_for_set) = 0;
	virtual void SetDes(vector<int> buffer) = 0;
	virtual void Move(int dx, int dy) = 0; //�ƶ�ͼƬ
	virtual queue<int> OutObjPos() = 0;
	virtual bool IsChoosed(int x0, int y0) = 0; //�ж�ͼƬ�Ƿ�ѡ��
	virtual bool HandleMsg(message_for_shapes msg) = 0; //�κ�ʹ�øýӿڵ������ʵ����Ϣ�������
};

