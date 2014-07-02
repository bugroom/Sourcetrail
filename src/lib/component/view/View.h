#ifndef VIEW_H
#define VIEW_H

#include <memory>
#include <string>

#include "component/view/ViewLayout.h"
#include "utility/math/Vector2.h"

class GuiWidgetWrapper;
class ViewLayout;

class View
{
public:
	template<typename T>
	static std::shared_ptr<T> create(ViewLayout* viewLayout);

	virtual ~View();

	virtual std::string getName() const = 0;

	virtual void createWidgetWrapper() = 0;
	void setWidgetWrapper(std::shared_ptr<GuiWidgetWrapper> widgetWrapper);
	GuiWidgetWrapper* getWidgetWrapper();

	virtual void initGui() = 0;

	int getMinWidth() const;
	int getMinHeight() const;
	Vec2i getMinSize() const;

protected:
	View(ViewLayout* viewLayout, const Vec2i& minSize);

private:
	ViewLayout* const m_viewLayout;
	std::shared_ptr<GuiWidgetWrapper> m_widgetWrapper;
	Vec2i m_minSize;
};

template<typename T>
std::shared_ptr<T> View::create(ViewLayout* viewLayout)
{
	std::shared_ptr<T> ptr = std::make_shared<T>(viewLayout);

	ptr->createWidgetWrapper();
	ptr->initGui();

	viewLayout->addView(ptr.get());

	return ptr;
}

#endif // VIEW_H
