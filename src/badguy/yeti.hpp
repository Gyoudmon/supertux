//  SuperTux - Boss "Yeti"
//  Copyright (C) 2005 Matthias Braun <matze@braunis.de>
//  Copyright (C) 2006 Christoph Sommer <christoph.sommer@2006.expires.deltadevelopment.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_BADGUY_YETI_HPP
#define HEADER_SUPERTUX_BADGUY_YETI_HPP

#include "badguy/badguy.hpp"

class Yeti final : public BadGuy
{
public:
  Yeti(const ReaderMapping& mapping);

  virtual void draw(DrawingContext& context) override;
  virtual void initialize() override;
  virtual void active_update(float dt_sec) override;
  virtual void collision_solid(const CollisionHit& hit) override;
  virtual bool collision_squished(GameObject& object) override;
  virtual void kill_fall() override;

  virtual bool is_flammable() const override;
  static std::string class_name() { return "yeti"; }
  virtual std::string get_class_name() const override { return class_name(); }
  static std::string display_name() { return _("Yeti"); }
  virtual std::string get_display_name() const override { return display_name(); }

  virtual ObjectSettings get_settings() override;

  void kill_squished(GameObject& object);

private:
  void run();
  void jump_up();
  void be_angry();
  void drop_stalactite();
  void jump_down();

  void draw_hit_points(DrawingContext& context);

  void take_hit(Player& player);

  void add_snow_explosions();

private:
  enum YetiState {
    JUMP_DOWN,
    RUN,
    JUMP_UP,
    BE_ANGRY,
    SQUISHED,
    FALLING
  };

private:
  YetiState state;
  Timer state_timer;
  Timer safe_timer;
  int stomp_count;
  int hit_points;
  SurfacePtr hud_head;

  float left_stand_x;
  float right_stand_x;
  float left_jump_x;
  float right_jump_x;

  void recalculate_pos();

  bool fixed_pos;
  std::string hud_icon;

  class SnowExplosionParticle: public BadGuy
  {
  public:
    SnowExplosionParticle(const Vector& pos, const Vector& velocity);
  };

private:
  Yeti(const Yeti&) = delete;
  Yeti& operator=(const Yeti&) = delete;
};

#endif

/* EOF */
