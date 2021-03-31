#include "mouse_event.h"

void MouseEventFactor::LeftButtonClick()
{
	x2 = x1;
	y2 = y1;
}

void MouseEventFactor::LeftDoubleClick()
{
	x2 = x1 = LOWORD(lParam);
	y2 = y1 = HIWORD(lParam);
}

void MouseEventFactor::LeftButtonDown()
{
	queue<int> msg_temp;
	switch (choice) {
	case MOVEEVENT:
		x2 = x1 = LOWORD(lParam);
		y2 = y1 = HIWORD(lParam);
		msg_temp.push(x1);
		msg_temp.push(y1);
		msg_temp.push(x2);
		msg_temp.push(y2);
		msg_to_shape = { SETPOINTSUSPEND,msg_temp ,choice, FALSE};
		loader = 1;
		break;
	case LINEEVENT:
		x1 = LOWORD(lParam);
		y1 = HIWORD(lParam);
		loader = 0;
		break;
	case RECTEVENT:
		break;
	case CIREVENT:
		break;
	default:
		break;
	}
}

void MouseEventFactor::LeftButtonUp()
{
	queue<int> msg_temp;
	switch (choice) {
	case MOVEEVENT:
		x2 = x1 = LOWORD(lParam);
		y2 = y1 = HIWORD(lParam);
		msg_temp.push(x1);
		msg_temp.push(y1);
		msg_temp.push(x2);
		msg_temp.push(y2);
		msg_to_shape = { SETPOINTOFF,msg_temp,choice ,FALSE };
		loader = 1;
		break;
	case LINEEVENT:
		x2 = LOWORD(lParam);
		y2 = HIWORD(lParam);
		msg_temp.push(x1);
		msg_temp.push(y1);
		msg_temp.push(x2);
		msg_temp.push(y2);
		msg_to_shape = { SETPOINTON,msg_temp,choice ,FALSE };
		loader = 1;
		break;
	case RECTEVENT:
		break;
	case CIREVENT:
		break;
	default:
		break;
	}
}

void MouseEventFactor::MouseMoving()
{
	queue<int> msg_temp;
	if (choice == MOVEEVENT && wParam == MK_LBUTTON) {
		x2 = x1 = LOWORD(lParam);
		y2 = y1 = HIWORD(lParam);
		msg_temp.push(x1);
		msg_temp.push(y1);
		msg_temp.push(x2);
		msg_temp.push(y2);
		msg_to_shape = { SETPOINTSUSPEND,msg_temp ,choice ,TRUE};
		loader = 1;
	}
	else loader = 0;
}

bool MouseEventFactor::IsLoader()
{
	return loader;
}


message_for_shapes MouseEventFactor::GetEvent(UINT msg, WPARAM wParam, LPARAM lParam, Choice choice)
{
	MouseEventFactor::msg = msg;
	MouseEventFactor::wParam = wParam;
	MouseEventFactor::lParam = lParam;
	MouseEventFactor::choice = choice;
	MouseEventSelector();
	return msg_to_shape;
}

void MouseEventFactor::MouseEventSelector()
{
	switch (msg) 
	{
	case WM_LBUTTONDOWN:
		LeftButtonDown();
		break;
	case WM_LBUTTONUP:
		LeftButtonUp();
		break;
	case WM_LBUTTONDBLCLK:
		LeftDoubleClick();
		break;
	case WM_MOUSEMOVE: 
		MouseMoving();
		break;
	default:
		break;
	}

}
