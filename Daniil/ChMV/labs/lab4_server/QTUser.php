<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class QTUser extends Model
{
    public $timestamps = false;

    protected $fillable = [
        'login',
        'password',
        'type',
        'email'
    ];
}
