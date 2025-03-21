#pragma once
#include <glm/vec2.hpp>
#include <vector>
#include <string>

namespace sf
{
	class RenderWindow;
}

class ConvexHullBase
{
public:
	ConvexHullBase(const std::vector<glm::ivec2>& _points, const std::string outputFile = "");
	ConvexHullBase(const ConvexHullBase& rhs) = default;
	virtual ~ConvexHullBase() = default;

	virtual std::vector<glm::ivec2> GenerateConvexHull() = 0;
	virtual void Draw(sf::RenderWindow& window);
	size_t GetConvexHullCount() const { return m_convexHullIndices.size(); }
protected:
	void SavePointsToFile(std::vector<glm::ivec2> _points);
	

	std::vector<int> m_convexHullIndices;
	std::vector<glm::ivec2> m_points;
	std::string m_outputFile;
};