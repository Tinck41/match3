#include "m3pch.h"
#include "EditorLayer.h"

#include <imgui.h> 
#include <imgui-SFML.h>

EditorLayer::EditorLayer()
{
    Init();
}

EditorLayer::~EditorLayer()
{

}

void EditorLayer::SetScene(std::shared_ptr<Scene> scene)
{
    m_ActiveScene = scene;
}

void EditorLayer::Init()
{


}

void EditorLayer::Update(float dt)
{

}

void EditorLayer::Render(sf::RenderWindow& window)
{
    ImGui::Begin("match3");

    auto& reg = m_ActiveScene->GetRegistry();

    //Transfrom Component
    if (ImGui::TreeNode("Transform"))
    {
        auto view = reg.view<TransformComponent>();
        for (auto e : view)
        {
            auto& transform = reg.get<TransformComponent>(e);
            float value[2] = { transform.translation.x, transform.translation.y };

            if (ImGui::DragFloat2("XY", value, 0.1f))
            {
                transform.translation.x = (value[0]);
                transform.translation.y = (value[1]);
            }
        }

        ImGui::TreePop();
    }

    //Grid Component
    if (ImGui::TreeNode("Grid")) {

        auto view = reg.view<GridComponent>();
        for (auto e : view)
        {
            auto& grid = reg.get<GridComponent>(e);
            int value[2] = { grid.rows, grid.columns };
            float cell[2] = { grid.cellSize.x, grid.cellSize.y };

            if (ImGui::DragInt2("XY", value, 0.1f))
            {
                grid.rows = (value[0]);
                grid.columns = (value[1]);
            }

            if (ImGui::DragFloat2("Cell size", cell, 0.1f))
            {
                grid.cellSize.x = (cell[0]);
                grid.cellSize.y = (cell[1]);
            }
        }

        ImGui::TreePop();
    }

    //Sprite Component
    if (ImGui::TreeNode("Sprite")) {

        auto view = reg.view<SpriteComponent>();
        for (auto e : view)
        {
            auto& sprite = reg.get<SpriteComponent>(e);
            float value[4] = { sprite.color.r / 255.f, sprite.color.g / 255.f, sprite.color.b / 255.f, sprite.color.a / 255.f };

            if (ImGui::ColorEdit4("RGBA", value, 0.1f))
            {
                sprite.color.r = (value[0] * 255.f);
                sprite.color.g = (value[1] * 255.f);
                sprite.color.b = (value[2] * 255.f);
                sprite.color.a = (value[3] * 255.f);
            }
        }

        ImGui::TreePop();
    }

    ImGui::End();

}
