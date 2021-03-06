//       $Id: impl_canvas.h 626 2020-01-12 16:28:28Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/minilib/ml5/trunk/product/ml5/inc/ml5/gui/impl/impl_canvas.h $
// $Revision: 626 $
//     $Date: 2020-01-12 17:28:28 +0100 (So., 12 Jän 2020) $
//   Creator: peter.kulczycki<AT>fh-hagenberg.at
//  Creation: June 1, 2018
//   $Author: p20068 $
// Copyright: (c) 2018 Peter Kulczycki (peter.kulczycki<AT>fh-hagenberg.at)
//            (c) 2018 Michael Hava (michael.hava<AT>fh-hagenberg.at)
//   License: This document contains proprietary information belonging to
//            University of Applied Sciences Upper Austria, Campus Hagenberg. It
//            is distributed under the Boost Software License, Version 1.0 (see
//            http://www.boost.org/LICENSE_1_0.txt).

#pragma once

#include "../events.h"

namespace ml5::impl {

class ML5_DLL_EXPORT canvas final : public wxGLCanvas {
   friend class frame;

   public:
      canvas (canvas const &) = delete;
      canvas (canvas &&) = delete;

     ~canvas () = default;

      canvas & operator = (canvas const &) = delete;
      canvas & operator = (canvas &&) = delete;

      void restart_timer (duration_t interval);
      void start_timer   (duration_t interval);
      void stop_timer    ();

   private:
      explicit canvas (window & win, wxWindow & parent);

      ML5_DECLARE_GET_WIN_PROPERTY (background_brush, wxBrush)
      ML5_DECLARE_GET_WIN_PROPERTY (paint_via_opengl, bool)

      void               bind_event_handlers ();
      void               capture_mouse       ();
      void               fire_idle           (idle_event const &) const;
      void               fire_key            (key_event const &) const;
      void               fire_mouse_dd       (mouse_event const &) const;
      void               fire_mouse_down     (mouse_event const &) const;
      void               fire_mouse_ld       (mouse_event const &) const;
      void               fire_mouse_ldd      (mouse_event const &) const;
      void               fire_mouse_lu       (mouse_event const &) const;
      void               fire_mouse_move     (mouse_event const &) const;
      void               fire_mouse_rd       (mouse_event const &) const;
      void               fire_mouse_rdd      (mouse_event const &) const;
      void               fire_mouse_ru       (mouse_event const &) const;
      void               fire_mouse_up       (mouse_event const &) const;
      void               fire_mouse_wheel    (mouse_event const &) const;
      void               fire_paint          (paint_event const &) const;
      void               fire_size           (size_event const &) const;
      void               fire_timer          (timer_event const &) const;
      ml5::application & get_app             () const;
      window &           get_win             () const;
      void               initialize          ();
      void               release_mouse       ();

      int                           m_captures {0};
      std::unique_ptr <wxGLContext> m_context  {nullptr};
      duration_t                    m_interval {0};
      window *                      m_p_win    {nullptr};
//    wxTimer                       m_timer    {this};
};

}   // namespace ml5::impl
