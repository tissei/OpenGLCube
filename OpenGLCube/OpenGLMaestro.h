class OpenGLMaestro {
public:
	OpenGLMaestro(char* windowTitle, unsigned int displayMode);
	void Init(int argc, char** argv);
	static void DisplayCallback();
private:
	char* windowTitle;
	unsigned int displayMode;
	void StartWindow();
	void EnableCapability(unsigned int capability);
	void SetCallbacks();
	void GlutStart();
	static void ClearScreen(unsigned int mask);
	static void Prepare(unsigned int mode);
	static void Flush();
};