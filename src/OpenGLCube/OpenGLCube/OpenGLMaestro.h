class OpenGLMaestro {
public:
	OpenGLMaestro(char*, unsigned int);
	void Init(int, char**);
private:
	double rotateY;
	double rotateX;
	char* windowTitle;
	unsigned int displayMode;
	void Display();
	void Rotate(int, int, int);
};