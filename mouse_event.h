#include "framework.h"
#include "DrawBoard.h"

#define POINTNUM 100
#include <queue>

using std::queue;

enum  Events
{
	SETPOINTON,//���ݵ��¼��������õ����٣�ȷ������¼����޸Ĳ�Ӱ��ʹ��������
	SETPOINTOFF,
	SETPOINTSUSPEND, //���ƶ�ʱ����ʵ�����ǹ����
};

typedef struct {
	Events event_msg;
	queue<int> pos;
	Choice option;
	bool is_pressed=FALSE;
}message_to_shape_factor, message_for_shapes;


class MouseEventFactor
{
public:
	bool IsLoader();
	message_to_shape_factor msg_to_shape;
	MouseEventFactor() = default;
	~MouseEventFactor() = default;
	message_to_shape_factor GetEvent(UINT msg, WPARAM wParam, LPARAM lParam, Choice choice);
private:
	UINT msg;
	WPARAM wParam;
	LPARAM lParam;
	Choice choice;
	int x1, y1, x2, y2, loader = 0;//loader�����жϵ�ǰ�Ƿ�����Ϣ���ݱ�Ҫ��
	void MouseEventSelector();
	void LeftButtonClick();
	void LeftDoubleClick();
	void LeftButtonDown();
	void LeftButtonUp();
	void MouseMoving();
};

