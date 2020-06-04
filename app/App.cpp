#include "App.hpp"
// #include<iostream>

void App::Log(const FunctionCallbackInfo<Value>& args) {

	for(int i = 0; i < args.Length(); i++) {
		HandleScope scope(args.GetIsolate());

		if ( i > 0) {
			fprintf(stdout, " ");
		}
		String::Utf8Value str(args.GetIsolate(), args[i]);
		// const char* cstr = Helpers::ToCString(str);
		const char* cstr = StaticHelpers::ToCString(str);

		fprintf(stdout, "%s", cstr);
	}

	fprintf(stdout, "\n");
	fflush(stdout);
}

using namespace std;
// 1. call Start method automatically starts the applications inside a vitrual machine 
// inside the v8 engine alright 


void App::SetupEnvironment() {
	this->GetGlobal()->Set(
		String::NewFromUtf8(this->GetIsolate(), "log", NewStringType::kNormal).ToLocalChecked(),
		FunctionTemplate::New(this->GetIsolate(), App::Log)
	);
}


void App::Start(int argc, char* argv[]) {

//  2. loop the arguments 
	for (int i = 1; i < argc; ++i) {

		// Get filename of the javascript file to run
		const char* filename = argv[i];

// 	    3. create a context and then enters the context 
		// Create a new context for executing javascript code
		Local<Context> context = this->CreateLocalContext();

		// Enter the new context
		Context::Scope contextscope(context);
		// cout << "filename is :" << filename << endl;
		// Run the javascript file
		this->RunJsFromFile(filename);

	}

}