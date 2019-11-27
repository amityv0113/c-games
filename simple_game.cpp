#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

using namespace sf;

void update(RectangleShape &square,int &keytime ,RenderWindow &window)
{
   /* if (keytime<8)
    {
        keytime++;
    }*/
    if (Keyboard::isKeyPressed(Keyboard::A) && square.getPosition().x>0)
    {
        square.move(-5.f ,0.f);
        keytime=0;
    }
    if (Keyboard::isKeyPressed(Keyboard::D) && square.getPosition().x + square.getSize().x < window.getSize().x)
    {
        square.move(5.f ,0.f);
        keytime=0;
    }
    if (Keyboard::isKeyPressed(Keyboard::W) && square.getPosition().y>0)
    {
        square.move(0.f,-5.f);
        keytime=0;
    }
    if (Keyboard::isKeyPressed(Keyboard::S) && square.getPosition().y + square.getSize().y < window.getSize().y)
    {
        square.move(0.f,5.f);
        keytime=0;
    }
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        square.setFillColor(Color::Cyan);
        keytime=0;
    }
    else
    {
        square.setFillColor(Color::Red);
    }
    
}
void draw(RenderWindow &window ,RectangleShape &square)
{
    window.clear(Color::White);

    //draw stuff 
    window.draw(square);

    window.display();


}

int main()
{
    int keytime=8;
    RenderWindow window(VideoMode(640 ,500) ,"simple game");
    window.setFramerateLimit(60);

    //creation of square 
    RectangleShape square(Vector2f(100.f,100.f));
    square.setFillColor(Color::Red);
    square.setPosition(window.getSize().x/2 ,window.getSize().y/2);



    while(window.isOpen())
    {
        Event event;

        while(window.pollEvent(event))
        {
            if (event.type==Event::Closed)
            {
                window.close();
            }
            if (event.type==Event::KeyPressed && event.key.code==Keyboard::Escape)
            {
                window.close();
            }
            /*if (event.type==Event::MouseButtonPressed)
            {
                window.close();
            }*/
        }

        update(square,keytime,window); 

    
        draw(window,square);    


    }


    return 0;
}