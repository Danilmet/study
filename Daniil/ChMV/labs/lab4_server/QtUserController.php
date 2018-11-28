<?php

namespace App\Http\Controllers;

use App\QTUser;
use Illuminate\Http\Request;

class QtUserController extends Controller
{
    public function store(Request $request)
    {
        $request->validate([
            'login' => 'required',
            'password' => 'required',
            'email' => 'required',
            'type' => 'required'
        ]);

        $qtUser = new QTUser();

        $qtUser->login = $request->input('login');
        $qtUser->password = bcrypt($request->input('password'));
        $qtUser->email = $request->input('email');
        $qtUser->type = $request->input('type');

        $qtUser->save();

        return response('Пользователь создан', 200);
    }

    public function auth(Request $request)
    {
        $request->validate([
            'login' => 'required',
            'password' => 'required'
        ]);

        $login = $request->input('login');
        $password = bcrypt($request->input('password'));

        $user = QTUser::where('login', $login)->where('password', $password)->get();

        return response($user ? $user->role : 'Неверный логин/пароль', 200);
    }

    public function getAll(Request $request)
    {
        $all = QTUser::all();

        return response($all->toJson(), 200);
    }

    public function setPassword(Request $request)
    {
        $request->validate([
            'email' => 'required'
        ]);

        $email = $request->input('email');

        $user = QTUser::where('email', $email)->get();
        $user->password = bcrypt($request->input('password'));
        $user->save();

        return response('Пароль успешно изменен!', 200);
    }

    public function deleteUser(Request $request)
    {
        $user = QTUser::where('login', $request->input('login'))->delete();
    }

    public function editUser(Request $request)
    {
        $qtUser = QTUser::where('id', $request->input('id'));

        $qtUser->login = $request->input('login');
        $qtUser->password = bcrypt($request->input('password'));
        $qtUser->email = $request->input('email');
        $qtUser->type = $request->input('type');

        $qtUser->save();

        return response('Пользователь изменен!', 200);
    }
}
