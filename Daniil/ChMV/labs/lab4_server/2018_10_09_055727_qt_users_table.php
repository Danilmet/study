<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class QtUsersTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        if (!Schema::hasTable('q_t_users')) {
            Schema::create('q_t_users', function (Blueprint $table) {
                $table->increments('id');
                $table->string('login')->nullable()->default(null);
                $table->string('password')->nullable()->default(null);
                $table->enum('role', ['admin', 'user']);
                $table->string('email')->nullable()->default(null);
            });
        }
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('q_t_users');
    }
}
