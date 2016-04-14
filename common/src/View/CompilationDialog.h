/*
 Copyright (C) 2010-2016 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CompilationDialog_h
#define CompilationDialog_h

#include <wx/dialog.h>

class wxTextCtrl;

namespace TrenchBroom {
    namespace View {
        class CompilationProfileManager;
        class CompilationRunner;
        class MapFrame;
        
        class CompilationDialog : public wxDialog {
        private:
            MapFrame* m_mapFrame;
            CompilationProfileManager* m_profileManager;
            wxTextCtrl* m_output;
            CompilationRunner* m_runner;
        public:
            CompilationDialog(MapFrame* mapFrame);
        private:
            void createGui();
            
            void OnCompileClicked(wxCommandEvent& event);
            void OnUpdateCompileButtonUI(wxUpdateUIEvent& event);
            void OnUpdateCloseButtonUI(wxUpdateUIEvent& event);
        };
    }
}

#endif /* CompilationDialog_h */
