#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"



class ExampleLayer : public Walnut::Layer
{
public:
	void OnUIRender() override
	{
		ImGui::Begin("Hello");
		ImGui::Button("Button1");
		ImGui::ShowDemoWindow();
		ImGui::End();
	}
};


class PlotLayer : public Walnut::Layer {
public:
	void OnUIRender() override {
		ImPlot::ShowDemoWindow();
	}
};



class AnalysisLayer : public Walnut::Layer {
public:
	void OnUIRender() override {
		ImGui::Begin("Hello2");
		ImGui::Button("Button2");
		ImGui::End();

	}
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Walnut Example";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<AnalysisLayer>();
	app->PushLayer<PlotLayer>();
	app->PushLayer<ExampleLayer>();

	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}