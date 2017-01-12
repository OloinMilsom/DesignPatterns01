#include <iostream>

using namespace std;

class IGraphic {
public:
	IGraphic() {
	}

	~IGraphic() {
	}

	virtual void Draw() = 0;
};

class Graphic : public IGraphic {
public:
	Graphic() {

	}

	~Graphic() {

	}

	void Draw() {
		cout << "Drawing Graphic Object" << endl;
	}
};

class GraphicProxy : public IGraphic {
public:
	GraphicProxy() {
		this->graphic = 0;
	}

	~GraphicProxy() {
		if (graphic) {
			delete graphic;
		}
	}

	void Draw() {
		getInstance()->Draw();
	}

private:
	Graphic* graphic;
	Graphic* getInstance(void) {
		if (!graphic) {
			graphic = new Graphic();
		}
		return graphic;
	}
};

int main(void) {
	GraphicProxy gp;
	gp.Draw();
	system("PAUSE");
}


