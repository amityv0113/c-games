#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1000 ,800), "window SFML");
    window.setFramerateLimit(60);

    int time=0;
    int enemytime =0;
    //ball that represent player :-----
    CircleShape player;
    player.setRadius(30.f);
    player.setFillColor(Color::Cyan);
    player.setPosition(Vector2f(window.getSize().x/2-player.getRadius(),(window.getSize().y-player.getRadius()*2)-10.f));
    //balls that use to intersect the enemy :---
    
    CircleShape ball;
    ball.setRadius(5.f);
    ball.setFillColor(Color::Yellow);

    vector<CircleShape>small_balls;
    small_balls.push_back(CircleShape(ball));

    //this is vector because there are no. of enemy not just one.shape is square

    RectangleShape enemy;
    enemy.setSize(Vector2f(60.f,40.f));
    enemy.setFillColor(Color::Red);
    
    vector<RectangleShape >enemies;
    enemies.push_back(RectangleShape(enemy));
                                
    //to trace position of player
    Vector2f playercenter;

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if (event.type==Event::Closed)
            {
                window.close();
            }
            /*if (event.type==Event::KeyPressed && event.key.code==Keyboard::Escape)
            {
                window.close();
            }*/
        }
        //update 
        //player :----------
        playercenter=Vector2f(player.getPosition().x+player.getRadius(),player.getPosition().y+player.getRadius());
        if (time <3)
        {
            time++;
        }
        if (Mouse::isButtonPressed(Mouse::Left) && time>=3)
        {
            ball.setPosition(playercenter);
            small_balls.push_back(CircleShape(ball));
            time=0;

        }
        //ball :----------
        for (int i=0 ;i<small_balls.size(); i++)
        {
            small_balls[i].move(0.f,-10.f);

            if (small_balls[i].getPosition().y<=10)
            {
                small_balls.erase(small_balls.begin()+i);
            }
        }
        //set position of player with mouse configuration:----

        player.setPosition(Mouse::getPosition(window).x,player.getPosition().y);

        //enemy : -------
        if (enemytime<20)
        {
            enemytime++;
        }
        if (enemytime>=20)
        {
            enemy.setPosition(rand()%int(window.getSize().x-enemy.getSize().x),0.f);
            enemies.push_back(RectangleShape(enemy));
            enemytime=0;

        }
        int a=window.getSize().y;
        for (int i=0 ;i<enemies.size() ;i++)
        {
            enemies[i].move(0.f ,5.f);
            if (enemies[i].getPosition().y>(a-10.f))
            {
                enemies.erase(enemies.begin()+i);
            }
            
        }
        //for collision of enemies and balls
        long long int count=0;
        long long int count_not=0;
        if (!enemies.empty() && !small_balls.empty())
		{
			for (long int  i = 0; i < small_balls.size(); i++)
			{
				for (int  j = 0; j < enemies.size(); j++)
				{
					if (small_balls[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds()))
					{
						small_balls.erase(small_balls.begin() + i);
						enemies.erase(enemies.begin() + j);
						break;
					}
				}
			}
		}
        

        window.clear(Color::White);


        //draw
        window.draw(player);
        
        for (int i=0 ;i<enemies.size() ;i++)
        {
            window.draw(RectangleShape(enemies[i]));
        }
        for (int i=0 ;i<small_balls.size() ;i++)
        {
            window.draw(CircleShape(small_balls[i]));
        }

        window.display();

    }


    return 0;
}