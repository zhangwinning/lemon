#ifndef APP
#define APP

#include "../engine/Lemon.hpp"

using v8::Context;
using v8::FunctionCallbackInfo;
using v8::HandleScope;
// using v8;

class App : public Lemon {

	public:	

		void Start(int argc, char* argv[]);
		//  which is called before the app starts 
		void SetupEnvironment();
		static void Log(const FunctionCallbackInfo<Value>& args);
		
};

#endif