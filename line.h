#include "shape_factor.h"
#include <cmath>

#define YES 1
#define NO 0

class LineFactor :
	public ShapeFactor
{
public:
	LineFactor()=default;
	~LineFactor() = default;
	void Paint() override;   //��ͼ
	void SetDes(vector<int> buffer) override;
	void SetDC(HDC hdc_for_set) override;
	void Move(int dx,int dy) override; //�ƶ�ͼƬ
	bool IsChoosed(int x0,int y0) override; //�ж�ͼƬ�Ƿ�ѡ��
	bool HandleMsg(message_for_shapes msg) override;
	queue<int> OutObjPos() override;
private:
	int x1, y1, x2, y2;
	int cx, cy;//��ѡ��Ϊ�ƶ�ʱ��ѡ��ֱ�ߺ�����cx,cy
	bool ischoosed;
	HDC hdc;
};
