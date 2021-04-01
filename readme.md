#使用方法
##引入图形插件，依照以下步骤。
1.打开DrawBoard.rc中的IDC_DRAWBOARD并按照图形界面提示插入菜单项，右击属性为自定义图形设置ID。
2.在DrawBoard.h中加入自定义图形event
3.在DrawBoard.cpp中的LRESULT CALLBACK WndProc依照实例编写对菜单id的响应
4.在record.h中找到InitLoader并在其中按照将自定义图片插入哈希表
5.阅读ShapeFactor,编写符合要求的自定义图形插件
