#ifndef TOOL_H
#define TOOL_H

class Tool
{
	protected:
		int strength;
		char type;

	public:
		Tool();
		virtual void setStrength(const int);
		virtual ~Tool();
};

#endif // !TOOL_H



