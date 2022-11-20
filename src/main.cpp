//
// Created by Caio Carvalho on 19/11/22.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <imgui-SFML.h>
#include <imgui.h>
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH    1280
#define SCREEN_HEIGHT   720

int main() {
    sf::RenderWindow window(
    sf::VideoMode(
        SCREEN_WIDTH,
        SCREEN_HEIGHT
    ), "Cmake - ImGui - SFML - Two Number Sum approaches animation");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Yellow);

    float  my_color[4] = {(float)255/255, (float)0/255, (float)0/255, (float)255/255};

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
        ImGui::TextColored(sf::Color::Yellow, "Hi! :)");

        ImGui::ColorEdit4("Color", my_color);

        shape.setFillColor(
            sf::Color(
                my_color[0] * 255,
                my_color[1] * 255,
                my_color[2] * 255,
                my_color[3] * 255
            )
        );

        float position_x, position_y;
        ImGui::SliderFloat("X Position", &position_x, 0.0f, (float)SCREEN_WIDTH);
        ImGui::SliderFloat("Y Position", &position_y, 0.0f, (float)SCREEN_HEIGHT);

        shape.setPosition(position_x, position_y);

        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.draw(shape);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
