#include <vector>
#include "shape_factor.h"
#include "line.h"

#define MAXSHAPE 10
#define MAXPOINT 100
#define END -1
//record类作为中轴线串连各个类
using std::vector;

/*template <typename T>
class ShapeContainer {
public:
	ShapeFactor* NewObj();
};

template<typename T>
inline ShapeFactor* ShapeContainer<T>::NewObj()
{
	ShapeFactor* ptr = new T;
	return ptr;
}

union ShapeLoader {
	ShapeContainer<LineFactor>;
};*/

class RecordFactor
{
public:
	RecordFactor() = default;
	~RecordFactor()=default;
	void RespondEvent(message_for_shapes msg);
	void GetWnd(HWND hWnd);
	void GetWndDC(HDC hdc);
	void PaintEvent();
	vector<ShapeFactor*> vec;
private:
	HDC hdc;
	message_for_shapes msg;
	HWND hWnd;
	vector<int> buffer;
	//ShapeContainer<ShapeFactor> shape_container[MAXPOINT];
	int slFlag = 0;
	int index = 0;
	void NewObject();
};

