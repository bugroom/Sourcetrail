#ifndef EDGE_H
#define EDGE_H

#include <memory>
#include <string>

#include "data/graph/Token.h"

class Node;
class TokenComponentAccess;
class TokenComponentDataType;

class Edge: public Token
{
public:
	typedef int EdgeTypeMask;
	enum EdgeType : EdgeTypeMask
	{
		EDGE_MEMBER            = 0x1,
		EDGE_TYPE_OF           = 0x2,
		EDGE_RETURN_TYPE_OF    = 0x4,
		EDGE_PARAMETER_TYPE_OF = 0x8,
		EDGE_TYPE_USAGE        = 0x10,
		EDGE_USAGE             = 0x20,
		EDGE_CALL              = 0x40,
		EDGE_INHERITANCE       = 0x80,
		EDGE_TYPEDEF_OF        = 0x100
	};

	Edge(EdgeType type, Node* from, Node* to);
	Edge(const Edge& other, Node* from, Node* to);
	virtual ~Edge();

	EdgeType getType() const;
	bool isType(EdgeTypeMask mask) const;

	Node* getFrom() const;
	Node* getTo() const;

	std::string getName() const;

	// Token implementation
	virtual bool isNode() const;
	virtual bool isEdge() const;

	// Component setters
	void addComponentAccess(std::shared_ptr<TokenComponentAccess> component);
	void addComponentDataType(std::shared_ptr<TokenComponentDataType> component);

	// Logging.
	std::string getTypeString(EdgeType type) const;
	virtual std::string getTypeString() const;
	std::string getAsString() const;

private:
	void operator=(const Node&);

	bool checkType() const;

	const EdgeType m_type;

	Node* const m_from;
	Node* const m_to;
};

std::ostream& operator<<(std::ostream& ostream, const Edge& edge);

#endif // EDGE_H
