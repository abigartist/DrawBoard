#include "record_factor.h"

void RecordFactor::RespondEvent(message_for_shapes msg)
{
	RecordFactor::msg = msg;
	if (msg.event_msg == SETPOINTON) {
		while (!msg.pos.empty()) {
			buffer.push_back(msg.pos.front());//将pos中全部进入缓存
			msg.pos.pop();
		}
		NewObject();
		while (!buffer.empty()) {
			buffer.pop_back();
		}
	}
	else if(msg.event_msg == SETPOINTSUSPEND)
	{
		for (int index = RecordFactor::index; index < vec.size(); index++) {
			if (vec[index]->HandleMsg(msg)) {
				if (msg.is_pressed) RecordFactor::index = index;
				break;
			}
		}
	}
	else if(msg.event_msg == SETPOINTOFF){
		index = 0;
		for (int index = RecordFactor::index; index < vec.size(); index++) {
			vec[index]->HandleMsg(msg);
		}
	}

	InvalidateRect(hWnd, nullptr, TRUE);
}

void RecordFactor::PaintEvent()
{
	for (int index = 0; index < vec.size(); index++) {
		vec[index]->SetDC(hdc);
		vec[index]->Paint();
	}
}




void RecordFactor::NewObject()
{
	ShapeFactor* ptr = nullptr;
	switch (msg.option) {
	case LINEEVENT:
		ptr = new LineFactor;
		ptr->SetDes(buffer);
		vec.push_back(ptr);
		break;
	default:
		break;
	}
	//ShapeFactor* ptr = shape_loader.line_factor.NewObj();
	//ptr->SetDes(buffer);
	//ShapeFactor* ptr = new LineFactor(msg.posx1,msg.posy1,msg.posx2,msg.posy2);
	//vec.push_back(ptr);
}


void RecordFactor::GetWnd(HWND hWnd)
{
	RecordFactor::hWnd = hWnd;
}

void RecordFactor::GetWndDC(HDC hdc)
{
	RecordFactor::hdc = hdc;
}
