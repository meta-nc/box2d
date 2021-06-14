// MIT License

// Copyright (c) 2019 Erin Catto

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "test.h"

class JMScene: public Test
{
public:

	JMScene()
	{
		float density = 100.0f;
		m_world->SetGravity(b2Vec2(0.0f,-1.0f));
		{
			b2PolygonShape shape;
			shape.SetAsBox(5.5f, 1.5f);
			b2BodyDef bd;
			bd.type = b2_staticBody;
			bd.position.Set(0.0f,0.0f);
			bd.bullet = true;
			b2Body* body = m_world->CreateBody(&bd);
			body->CreateFixture(&shape, density);
		}

		{
			b2PolygonShape shape;
			const b2Vec2 points[] = {b2Vec2(-1.0f, -1.0f), b2Vec2(1.0f, 1.0f), b2Vec2(-1.0f, 1.0f), b2Vec2(1.0f, -1.0f)};
			shape.Set(points, 4);

			for (int i = 0; i < 3; i++) {
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(0.0f, (float)i * 2.5f + 3.0f);
				bd.bullet = true;
				b2Body* body = m_world->CreateBody(&bd);
				body->CreateFixture(&shape, density);
			}
		}

		{
			b2PolygonShape shape;
			float length_triangle = 2.0f;
			const b2Vec2 points[] = {b2Vec2(-length_triangle / 2.0f, 0.0f), b2Vec2(length_triangle / 2.0f, 0.0f), b2Vec2(0.0f, length_triangle*0.866f)};
			shape.Set(points, 3);

			for (int i = 0; i < 3; i++) {
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(0.0f, (float)i * 5.0f + 3.0f);
				bd.bullet = true;
				b2Body* body = m_world->CreateBody(&bd);
				body->CreateFixture(&shape, density);
			}
		}

	}

	static Test* Create()
	{
		return new JMScene;
	}
};

static int testIndex = RegisterTest("Benchmark", "JMScene", JMScene::Create);
