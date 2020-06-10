#include "Core/mvPythonModule.h"
#include "Core/mvApp.h"
#include "Core/AppItems/mvAppItems.h"
#include "Core/mvPythonTranslator.h"

namespace Marvel {

	PyObject* addPlot(PyObject* self, PyObject* args, PyObject* kwargs)
	{
		const char* name;
		int width, height;

		auto pl = mvPythonTranslator(args, kwargs, {
			mvPythonDataElement(mvPythonDataType::String, "name"),
			mvPythonDataElement(mvPythonDataType::Integer, "width"),
			mvPythonDataElement(mvPythonDataType::Integer, "height")
			});

		pl.parse(__FUNCTION__, &name, &width, &height);

		mvAppItem* item = new mvPlot("", name, width, height);
		mvApp::GetApp()->addItem(item);

		Py_INCREF(Py_None);
		return Py_None;
	}

	void CreatePlotInterface(mvPythonModule& pyModule, PyObject* (*initfunc)())
	{
		pyModule.addMethod(addPlot, "Not Documented");

		PyImport_AppendInittab(pyModule.getName(), initfunc);
	}
}