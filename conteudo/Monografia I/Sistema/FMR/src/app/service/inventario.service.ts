import { Injectable } from '@angular/core';
import { Router } from '@angular/router';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class InventarioService {

  constructor(private _router : Router,
              private _http : HttpClient) { }

  private baseUrl : string = "http://localhost:8080/inventario";

  getInventario() {
    return this._http.get(this.baseUrl);
  }
}
