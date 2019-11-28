#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1000 ,1000) ,"SFML window");
    window.setFramerateLimit(60);

    //triangle shape

    CircleShape triangle;
    triangle.setRadius(50.f);
    triangle.setPointCount(3);
    triangle.setPosition(100.f,100.f);
    triangle.setFillColor(Color::Cyan);
    triangle.setOutlineColor(Color::Blue);

    //stright line 

    Vertex line[] ={Vertex(Vector2f(10.f,50.f)),Vertex(Vector2f(100.f,50.f))};

    //convex shape

    ConvexShape convex;
    convex.setPosition(100.f,100.f);
    convex.setPointCount(5);
    convex.setPoint(0, Vector2f(0,0));
    convex.setPoint(1, Vector2f(150,10));
    convex.setPoint(2, Vector2f(120,90));
    convex.setPoint(3, Vector2f(30,100));
    convex.setPoint(4, Vector2f(0,50));


    while(window.isOpen())
    {
        Event event;

        while(window.pollEvent(event))
        {
            if (event.type==Event::Closed)
            {
                window.close();
            }
        }
        //update && move triangle
        triangle.move(1.f,1.f);
        //rotate triangle
        triangle.rotate(1.f);

        window.clear();
        
        //dispaly triangle;-----

        window.draw(triangle);

        //draw line
        window.draw(line,2,Lines);

        //draw convex 

        window.draw(convex);

        window.display();
    }

    return 0;
}