//
// Created by Caio Carvalho on 19/11/22.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <imgui-SFML.h>
#include <imgui.h>
#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Yellow);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Demo window");
        ImGui::Button("Hello!");

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Openx..", "Ctrl+O")) { /* Do stuff */ }
                if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
                if (ImGui::MenuItem("Close", "Ctrl+W"))  { }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        float  my_color[3];
        ImGui::ColorEdit3("Color", my_color);

        shape.setFillColor(
            sf::Color(
                (sf::Uint8)my_color[0] * 255,
                (sf::Uint8)my_color[1] * 255,
                (sf::Uint8)my_color[2] * 255
            )
        );

        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.draw(shape);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
