#include "m3pch.h"
#include "EditorLayer.h"

//#include <imgui.h> 

EditorLayer::EditorLayer()
{
    Init();
}

EditorLayer::~EditorLayer()
{
}

void EditorLayer::Init()
{
//    ImGui::CreateContext();
//    ImGui::StyleColorsDark();
//
//    ImGuiIO& io = ImGui::GetIO();
//    ImFont* font1 = io.Fonts->AddFontDefault();
//    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
//    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
//
//    // init keyboard mapping
//    io.KeyMap[ImGuiKey_Tab] = sf::Keyboard::Tab;
//    io.KeyMap[ImGuiKey_LeftArrow] = sf::Keyboard::Left;
//    io.KeyMap[ImGuiKey_RightArrow] = sf::Keyboard::Right;
//    io.KeyMap[ImGuiKey_UpArrow] = sf::Keyboard::Up;
//    io.KeyMap[ImGuiKey_DownArrow] = sf::Keyboard::Down;
//    io.KeyMap[ImGuiKey_PageUp] = sf::Keyboard::PageUp;
//    io.KeyMap[ImGuiKey_PageDown] = sf::Keyboard::PageDown;
//    io.KeyMap[ImGuiKey_Home] = sf::Keyboard::Home;
//    io.KeyMap[ImGuiKey_End] = sf::Keyboard::End;
//    io.KeyMap[ImGuiKey_Insert] = sf::Keyboard::Insert;
//#ifdef ANDROID
//    io.KeyMap[ImGuiKey_Backspace] = sf::Keyboard::Delete;
//#else
//    io.KeyMap[ImGuiKey_Delete] = sf::Keyboard::Delete;
//    io.KeyMap[ImGuiKey_Backspace] = sf::Keyboard::BackSpace;
//#endif
//    io.KeyMap[ImGuiKey_Space] = sf::Keyboard::Space;
//    io.KeyMap[ImGuiKey_Enter] = sf::Keyboard::Return;
//    io.KeyMap[ImGuiKey_Escape] = sf::Keyboard::Escape;
//    io.KeyMap[ImGuiKey_A] = sf::Keyboard::A;
//    io.KeyMap[ImGuiKey_C] = sf::Keyboard::C;
//    io.KeyMap[ImGuiKey_V] = sf::Keyboard::V;
//    io.KeyMap[ImGuiKey_X] = sf::Keyboard::X;
//    io.KeyMap[ImGuiKey_Y] = sf::Keyboard::Y;
//    io.KeyMap[ImGuiKey_Z] = sf::Keyboard::Z;

}

void EditorLayer::Update(float dt)
{
    //ImGuiIO& io = ImGui::GetIO();
    //io.DisplaySize = ImVec2(800.f, 600.f);
    //io.DeltaTime = dt > 0.f ? (dt - m_Time) : (1.f / 60.f);
    //m_Time = dt;

    //ImGui::NewFrame();

    //static bool show = true;
    //ImGui::ShowDemoWindow(&show);

    //ImGui::Render();
}

void EditorLayer::Render(std::shared_ptr<sf::RenderWindow> window)
{
}
